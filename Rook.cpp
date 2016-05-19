#include "Rook.h"
#include <iostream>

using namespace std;

Rook::Rook(FigureColor color) :Figure("Rook  ", color) {}

bool Rook::move(int row, int col, int newRow, int newCol, Board& chess)
{
    if (!(((row==newRow+2 || row==newRow-2) && (col==newCol+1 || col==newCol-1)) || ((row==newRow+1 || row==newRow-1) && (col==newCol+2 || col==newCol-2))))
    {
        cout << "Illegal move. No action taken." << endl;
        return false;
    }
    if (!chess.isFree(newRow,newCol))
    {
        if ((chess.get_field(newRow,newCol)->getColor().isWhite() == true && chess.get_field(row,col)->getColor().isWhite() == true)
                || (chess.get_field(newRow,newCol)->getColor().isWhite() == false && chess.get_field(row,col)->getColor().isWhite() == false))
        {
            cout << "Illegal move. No action taken." << endl;
            return false;
        }
        chess.take(newRow,newCol);
    }
    if (chess.get_field(row,col)->getColor().isWhite()) cout << "W ";
    else cout << "B ";
    chess.set_field(newRow,newCol,*this);
    chess.get_field(row,col)->setName("Free");
    cout << "Rook from ";
    chess.announce(row,col,newRow,newCol);
    return true;
}

bool Rook::canAttack(int row, int col, int newRow, int newCol, Board& chess)
{
    if (!(((row==newRow+2 || row==newRow-2) && (col==newCol+1 || col==newCol-1)) || ((row==newRow+1 || row==newRow-1) && (col==newCol+2 || col==newCol-2))))
    {
        return false;
    }
    if (!chess.isFree(newRow,newCol))
    {
        if ((chess.get_field(newRow,newCol)->getColor().isWhite() == true && chess.get_field(row,col)->getColor().isWhite() == true)
                || (chess.get_field(newRow,newCol)->getColor().isWhite() == false && chess.get_field(row,col)->getColor().isWhite() == false))
            return false;
    }
    return true;
}
