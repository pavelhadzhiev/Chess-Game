#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>
#include <cassert>

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
    cout << "                                  Chessboard:" << endl << endl;
    cout << "          A        B        C        D        E        F        G        H";
    for (int row=7; row>=0; row--)
    {
        cout << endl << endl << endl << endl;
        cout << " " << row + 1 << "     ";
        for (int col=0; col<8; col++)
        {
            board[row][col].print();
            cout << " ";
            if(!strcmp(board[row][col].getName(),"Free"))
            cout << "        ";
        }
    }
    cout << endl << endl << endl << endl;
}

void Board::print_taken()const
{
    cout << "Taken figures: " << endl;
    for (int row=7; row>=0; row--)
    {
        for (int col=8; col<12; col++)
        {
            board[row][col].print();
            if (strcmp(board[row][col].getName(),"Free"))
            cout << endl;
        }
    }
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

    board[7][1] = black_rook; board[7][6] = black_rook;
    board[0][1] = white_rook; board[0][6] = white_rook;

    board [7][2] = black_knight; board[7][5] = black_knight;
    board [0][2] = white_knight; board[0][5] = white_knight;

    board [7][0] = black_bishop; board[7][7] = black_bishop;
    board [0][0] = white_bishop; board[0][7] = white_bishop;

    board [7][3] = black_queen;
    board [0][3] = white_queen;

    board [7][4] = black_king;
    board [0][4] = white_king;
}
