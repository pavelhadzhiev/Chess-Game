#include "Queen.h"
#include <iostream>

using namespace std;

Queen::Queen(FigureColor color) :Figure("Queen ", color){}

void Queen::move(int row, int col, int newRow, int newCol, Board& chess)
{
    bool flag = true;
    if((row - newRow != col - newCol && row - newRow != newCol - col) && (row!=newRow && col!=newCol))
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
        if (row==newRow)
        {
            if (col > newCol) for (int i=col-1; i>newCol; i--) if(!(chess.isFree(row,i)))flag = false;
            if (col < newCol) for (int i=col+1; i<newCol; i++) if(!(chess.isFree(row,i)))flag = false;
        }
        if (col==newCol)
        {
            if (row > newRow) for (int i=row-1; i>newRow; i--) if(!(chess.isFree(i,col)))flag = false;
            if (row < newRow) for (int i=row+1; i<newRow; i++) if(!(chess.isFree(i,col)))flag = false;
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
            cout << "Queen from "; chess.announce(row,col,newRow,newCol);
        }
        else cout << "Illegal move. No action taken." << endl;
    }
}
