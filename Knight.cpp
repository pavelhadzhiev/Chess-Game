#include "Knight.h"
#include <iostream>
#include <cmath>

using namespace std;

Knight::Knight(FigureColor color) :Figure("Knight", color){}

void Knight::move(int row, int col, int newRow, int newCol, Board& chess)
{
    bool flag = true;
    if(row - newRow != col - newCol && row - newRow != newCol - col)
        cout << "Illegal move. No action taken." << endl;
    else
    {
        if (row - newRow == col - newCol)
        {
            if (newRow - row > 0) for (int i=1; i<newRow-row; i++) if (!(chess.isFree(row+i,col+i))) flag = false;
            if (row - newRow > 0) for (int i=1; i<row-newRow; i++) if (!(chess.isFree(row-i,col-i))) flag = false;
        }
        if (row - newRow == newCol - col)
        {
            if (newRow - row > 0) for (int i=1; i<newRow-row; i++) if (!(chess.isFree(row+i,col-i))) flag = false;
            if (row - newRow > 0) for (int i=1; i<row-newRow; i++) if (!(chess.isFree(row-i,col=i))) flag = false;
        }
        if (!chess.isFree(newRow,newCol) && flag)
        {
            if ((chess.get_field(newRow,newCol)->getColor().isWhite() == true && chess.get_field(row,col)->getColor().isWhite() == true)
            || (chess.get_field(newRow,newCol)->getColor().isWhite() == false && chess.get_field(row,col)->getColor().isWhite() == false))
                flag = false;
            else
                chess.take(newRow,newCol);
        }
        if (flag)
        {
            if (chess.get_field(row,col)->getColor().isWhite()) cout << "W ";
            else cout << "B ";
            chess.set_field(newRow,newCol,*this);
            chess.get_field(row,col)->setName("Free");
            cout << "Knight from "; chess.announce(row,col,newRow,newCol);
        }
        else cout << "Illegal move. No action taken." << endl;
    }
}
