#include "Pawn.h"
#include <iostream>

using namespace std;

Pawn::Pawn(FigureColor color) :Figure("Pawn  ", color){}

void Pawn::move(int row, int col, int newRow, int newCol, Board& chess)
{
    if (this->getColor().isWhite())
    {
        if(((row+1==newRow && col==newCol) || (row==1 && newRow==3 && col==newCol)) && chess.isFree(newRow,newCol))
        {
            chess.set_field(newRow,newCol,*this);
            chess.get_field(row,col)->setName("Free");
            cout << "W Pawn from "; chess.announce(row,col,newRow,newCol);
        }
        else if(row+1==newRow && (col+1==newCol || col-1==newCol) && !chess.isFree(newRow,newCol) && chess.get_field(newRow,newCol)->getColor().isWhite() == false)
        {
            chess.take(newRow,newCol);
            chess.set_field(newRow,newCol,*this);
            chess.get_field(row,col)->setName("Free");
            cout << "W Pawn from "; chess.announce(row,col,newRow,newCol);
        }
        else cout << "Illegal move. No action taken." << endl;
    }

    else
    {
        if(((row-1==newRow && col==newCol) || (row==6 && newRow==4 && col==newCol)) && chess.isFree(newRow,newCol))
        {
            chess.set_field(newRow,newCol,*this);
            chess.get_field(row,col)->setName("Free");
            cout << "B Pawn from "; chess.announce(row,col,newRow,newCol);
        }
        else if(row-1==newRow && (col+1==newCol || col-1==newCol) && !chess.isFree(newRow,newCol) && chess.get_field(newRow,newCol)->getColor().isWhite() == true)
        {
            chess.take(newRow,newCol);
            chess.set_field(newRow,newCol,*this);
            chess.get_field(row,col)->setName("Free");
            cout << "B Pawn from "; chess.announce(row,col,newRow,newCol);
        }
        else cout << "Illegal move. No action taken." << endl;
    }
}
