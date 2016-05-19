#include "Knight.h"
#include <iostream>
#include <cmath>

using namespace std;

Knight::Knight(FigureColor color) :Figure("Knight", color) {}

bool Knight::move(int row, int col, int newRow, int newCol, Board& chess)
{
    if(row - newRow != col - newCol && row - newRow != newCol - col)
    {
        cout << "Illegal move. No action taken." << endl;
        return false;
    }
    if (row - newRow == col - newCol)
    {
        if (newRow - row > 0) for (int i=1; i<newRow-row; i++) if (!(chess.isFree(row+i,col+i)))
                {
                    cout << "Illegal move. No action taken." << endl;
                    return false;
                }
        if (row - newRow > 0) for (int i=1; i<row-newRow; i++) if (!(chess.isFree(row-i,col-i)))
                {
                    cout << "Illegal move. No action taken." << endl;
                    return false;
                }
    }
    if (row - newRow == newCol - col)
    {
        if (newRow - row > 0) for (int i=1; i<newRow-row; i++) if (!(chess.isFree(row+i,col-i)))
                {
                    cout << "Illegal move. No action taken." << endl;
                    return false;
                }
        if (row - newRow > 0) for (int i=1; i<row-newRow; i++) if (!(chess.isFree(row-i,col=i)))
                {
                    cout << "Illegal move. No action taken." << endl;
                    return false;
                }
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
    cout << "Knight from ";
    chess.announce(row,col,newRow,newCol);
    return true;
}

bool Knight::canAttack(int row, int col, int newRow, int newCol, Board& chess)
{
    if(row - newRow != col - newCol && row - newRow != newCol - col)
    {
        return false;
    }
    if (row - newRow == col - newCol)
    {
        if (newRow - row > 0) for (int i=1; i<newRow-row; i++) if (!(chess.isFree(row+i,col+i)))
                {
                    return false;
                }
        if (row - newRow > 0) for (int i=1; i<row-newRow; i++) if (!(chess.isFree(row-i,col-i)))
                {
                    return false;
                }
    }
    if (row - newRow == newCol - col)
    {
        if (newRow - row > 0) for (int i=1; i<newRow-row; i++) if (!(chess.isFree(row+i,col-i)))
                {
                    return false;
                }
        if (row - newRow > 0) for (int i=1; i<row-newRow; i++) if (!(chess.isFree(row-i,col=i)))
                {
                    return false;
                }
    }
    if (!chess.isFree(newRow,newCol))
    {
        if ((chess.get_field(newRow,newCol)->getColor().isWhite() == true && chess.get_field(row,col)->getColor().isWhite() == true)
                || (chess.get_field(newRow,newCol)->getColor().isWhite() == false && chess.get_field(row,col)->getColor().isWhite() == false))
        {
            return false;
        }
    }
    return true;
}
