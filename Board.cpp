#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

Board::Board()
{
    Figure blank;
    for (int row=0; row<8; row++)
    {
        for (int col=0; col<12; col++)
        {
            board[row][col] = blank;
        }
    }
}

void Board::set_field(int row, int col, Figure toSet)
{
    assert(row>=0 && row<=8 && col>=0 && col<=12);
    board[row][col] = toSet;
}

Figure* Board::get_field(int row, int col)
{
    return &board[row][col];
}

void Board::print_board()const
{
    for (int row=7; row>=0; row--)
    {
        cout << endl << endl << endl << endl << endl << endl;
        cout << " " << row + 1 << "    ";
        for (int col=0; col<8; col++)
        {
            board[row][col].print();
            cout << " ";
            if(board[row][col]=="Free")
            cout << "   .    ";
        }
    }
    cout << endl << endl << endl;
    cout << "          A        B        C        D        E        F        G        H";
    cout << endl << endl << endl << endl << endl;
}

void Board::print_taken()const
{
    cout << "Taken figures: " << endl;
    for (int row=7; row>=0; row--)
    {
        for (int col=8; col<12; col++)
        {
            board[row][col].print();
            if (!(board[row][col]=="Free"))
            cout << endl;
        }
    }
    cout << endl;
}

void Board::start()
{
    Pawn white_pawn(1), black_pawn(0);
    Rook white_rook(1), black_rook(0);
    Knight white_knight(1), black_knight(0);
    Bishop white_bishop(1), black_bishop(0);
    Queen white_queen(1), black_queen(0);
    King white_king(1), black_king(0);

    for (int col=0; col<8; col++)
    {
        board[6][col] = black_pawn;
    }
    for (int col=0; col<8; col++)
    {
        board[1][col] = white_pawn;
    }

    board[7][1] = black_rook  ; board[7][6] = black_rook  ;
    board[0][1] = white_rook  ; board[0][6] = white_rook  ;

    board[7][2] = black_knight; board[7][5] = black_knight;
    board[0][2] = white_knight; board[0][5] = white_knight;

    board[7][0] = black_bishop; board[7][7] = black_bishop;
    board[0][0] = white_bishop; board[0][7] = white_bishop;

    board[7][3] = black_queen ;
    board[0][3] = white_queen ;

    board[7][4] = black_king  ;
    board[0][4] = white_king  ;
}

bool Board::isFree(int row, int col)
{
    return *get_field(row,col)=="Free";
}

void Board::move(int row, int col, int newRow, int newCol)
{
    Figure toMove = *get_field(row, col);
    if (row<0 || row>7 || col<0 || col>7 || newRow<0 || newRow>7 || newCol<0 || newCol>7 || toMove=="Free" || (row==newRow && col==newCol))
        cout << "Illegal move. No action taken." << endl;
    else
    {
        if (toMove=="King  ") {King king(toMove.getColor().isWhite()); king.move(row,col,newRow,newCol,*this);}
        if (toMove=="Queen ") {Queen queen(toMove.getColor().isWhite()); queen.move(row,col,newRow,newCol,*this);}
        if (toMove=="Bishop") {Bishop bishop(toMove.getColor().isWhite()); bishop.move(row,col,newRow,newCol,*this);}
        if (toMove=="Knight") {Knight knight(toMove.getColor().isWhite()); knight.move(row,col,newRow,newCol,*this);}
        if (toMove=="Rook  ") {Rook rook(toMove.getColor().isWhite()); rook.move(row,col,newRow,newCol,*this);}
        if (toMove=="Pawn  ") {Pawn pawn(toMove.getColor().isWhite()); pawn.move(row,col,newRow,newCol,*this);}
    }
}

void Board::announce(int row, int col, int newRow, int newCol)
{
    switch (col)
    {
    case 0: cout << "A";break;
    case 1: cout << "B";break;
    case 2: cout << "C";break;
    case 3: cout << "D";break;
    case 4: cout << "E";break;
    case 5: cout << "F";break;
    case 6: cout << "G";break;
    case 7: cout << "H";break;
    }
    cout << row+1 << " to ";
    switch (newCol)
    {
    case 0: cout << "A";break;
    case 1: cout << "B";break;
    case 2: cout << "C";break;
    case 3: cout << "D";break;
    case 4: cout << "E";break;
    case 5: cout << "F";break;
    case 6: cout << "G";break;
    case 7: cout << "H";break;
    }
    cout << newRow+1 << endl;
}

void Board::take(int row, int col)
{
    bool flag = false;
    for (int j=8; j<=12; j++)
    {
        if (flag) break;
        for (int i=7; i>=0; i--)
        {
            if (this->isFree(i,j))
            {
                board[i][j] = board[row][col];
                flag = true;
                break;
            }
        }
    }
    board[row][col].setName("Free");
}

void Board::game()
{
    cout << "Game started." << endl << "Enter moves like this: 'A2 A3' or 'a2 a3'. " << endl << "Enter 'A0 A0' to end game. " << endl;
    start();
    print_board();
    char x1, x2;
    int row, col, newRow, newCol;
    while (!ended())
    {
        cin >> x1 >> row >> x2 >> newRow;
        if ((x1 == 'a' || x1 == 'A') && (x2 == 'a' || x2 == 'A') && row == 0 && newRow == 0)
            break;
        row--;
        newRow--;
        switch(x1)
        {
            case 'a': col = 0;break;
            case 'b': col = 1;break;
            case 'c': col = 2;break;
            case 'd': col = 3;break;
            case 'e': col = 4;break;
            case 'f': col = 5;break;
            case 'g': col = 6;break;
            case 'h': col = 7;break;
            case 'A': col = 0;break;
            case 'B': col = 1;break;
            case 'C': col = 2;break;
            case 'D': col = 3;break;
            case 'E': col = 4;break;
            case 'F': col = 5;break;
            case 'G': col = 6;break;
            case 'H': col = 7;break;
        }
        switch(x2)
        {
            case 'a': newCol = 0;break;
            case 'b': newCol = 1;break;
            case 'c': newCol = 2;break;
            case 'd': newCol = 3;break;
            case 'e': newCol = 4;break;
            case 'f': newCol = 5;break;
            case 'g': newCol = 6;break;
            case 'h': newCol = 7;break;
            case 'A': newCol = 0;break;
            case 'B': newCol = 1;break;
            case 'C': newCol = 2;break;
            case 'D': newCol = 3;break;
            case 'E': newCol = 4;break;
            case 'F': newCol = 5;break;
            case 'G': newCol = 6;break;
            case 'H': newCol = 7;break;
        }
        move(row,col,newRow,newCol);
        print_board();
        print_taken();
    }
    cout << "Game ended. " << endl;
}

bool Board::ended()
{
    for (int row=7; row>=0; row--)
    {
        for (int col=8; col<12; col++)
        {
            if (board[row][col] == "King  ")
            return true;
        }
    }
    return false;
}
