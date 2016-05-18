#include "King.h"
#include <iostream>
#include "Board.h"

using namespace std;

King::King(FigureColor color) :Figure("King  ", color){}

void King::move(int row, int col, int newRow, int newCol, Board& chess)
{
    bool flag = true;
    if (row > newRow+1 || row < newRow-1 || col > newCol+1 || col < newCol-1)
        cout << "Illegal move. No action taken." << endl;
    else
    {
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
            cout << "King from "; chess.announce(row,col,newRow,newCol);
        }
        else cout << "Illegal move. No action taken." << endl;
    }
}
