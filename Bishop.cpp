#include "Bishop.h"
#include <iostream>

using namespace std;

Bishop::Bishop(FigureColor color) :Figure("Bishop", color) {}

bool Bishop::move(int row, int col, int newRow, int newCol, Board& chess)
{
    if (row!=newRow && col!=newCol)
    {
        cout << "Illegal move. No action taken." << endl;
        return false;
    }

    if (row==newRow)
    {
        if (col > newCol) for (int i=col-1; i>newCol; i--) if(!(chess.isFree(row,i)))
                {
                    cout << "Illegal move. No action taken." << endl;
                    return false;
                }
        if (col < newCol) for (int i=col+1; i<newCol; i++) if(!(chess.isFree(row,i)))
                {
                    cout << "Illegal move. No action taken." << endl;
                    return false;
                }
    }
    if (col==newCol)
    {
        if (row > newRow) for (int i=row-1; i>newRow; i--) if(!(chess.isFree(i,col)))
                {
                    cout << "Illegal move. No action taken." << endl;
                    return false;
                }
        if (row < newRow) for (int i=row+1; i<newRow; i++) if(!(chess.isFree(i,col)))
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
    chess.get_field(row,col)->unmoved=false;
    cout << "Knight from ";
    chess.announce(row,col,newRow,newCol);
    return true;
}

bool Bishop::canAttack(int row, int col, int newRow, int newCol, Board& chess)
{
    if (row!=newRow && col!=newCol)
    {
        return false;
    }

    if (row==newRow)
    {
        if (col > newCol) for (int i=col-1; i>newCol; i--) if(!(chess.isFree(row,i)))
                {
                    return false;
                }
        if (col < newCol) for (int i=col+1; i<newCol; i++) if(!(chess.isFree(row,i)))
                {
                    return false;
                }
    }
    if (col==newCol)
    {
        if (row > newRow) for (int i=row-1; i>newRow; i--) if(!(chess.isFree(i,col)))
                {
                    return false;
                }
        if (row < newRow) for (int i=row+1; i<newRow; i++) if(!(chess.isFree(i,col)))
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
