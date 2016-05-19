#include "King.h"
#include <iostream>
#include "Board.h"

using namespace std;

King::King(FigureColor color) :Figure("King  ", color) {}

bool King::move(int row, int col, int newRow, int newCol, Board& chess)
{
    if ((chess.get_field(row,col)->getColor().isWhite() == true && row==0 && col ==4 && newRow==0 && (newCol==1 || newCol==6))
            || (chess.get_field(row,col)->getColor().isWhite() == false && row==7 && col ==4 && newRow==7 && (newCol==1 || newCol==6)))
        return castle(newRow,newCol,chess);
    if (row > newRow+1 || row < newRow-1 || col > newCol+1 || col < newCol-1)
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
    chess.get_field(row,col)->unmoved=false;
    cout << "King from ";
    chess.announce(row,col,newRow,newCol);
    return true;
}

bool King::castle(int newRow, int newCol, Board& chess)
{
    bool white = true;
    if (newCol==1)
    {
        if (chess.get_field(newRow,4)->unmoved && chess.get_field(newRow,0)->unmoved && chess.isFree(newRow,1) && chess.isFree(newRow,2) && chess.isFree(newRow,3))
        {
            if (newRow == 0)
            {
                if (chess.isAttacked(newRow,1,0) || chess.isAttacked(newRow,2,0) || chess.isAttacked(newRow,3,0))
                {
                    cout << "Illegal move. No action taken. " << endl;
                    return false;
                }
                cout << "W ";
            }
            else
            {
                if (chess.isAttacked(newRow,1,1) || chess.isAttacked(newRow,2,1) || chess.isAttacked(newRow,3,1))
                {
                    cout << "Illegal move. No action taken. " << endl;
                    return false;
                }
                cout << "B ";
                white=false;
            }
            Bishop bishop(white);
            chess.set_field(newRow,1,*this);
            chess.set_field(newRow,2,bishop);
            chess.get_field(newRow,0)->setName("Free");
            chess.get_field(newRow,4)->setName("Free");
            chess.get_field(newRow,0)->unmoved=false;
            chess.get_field(newRow,4)->unmoved=false;
            cout << "King castle to B1. " << endl;
            return true;
        }
    }
    if (newCol==6)
    {
        if (chess.get_field(newRow,4)->unmoved && chess.get_field(newRow,7)->unmoved && chess.isFree(newRow,5) && chess.isFree(newRow,6))
        {
            if (newRow == 0)
            {
                if (chess.isAttacked(newRow,5,0) || chess.isAttacked(newRow,6,0))
                {
                    cout << "Illegal move. No action taken. " << endl;
                    return false;
                }
                cout << "W ";
            }
            else
            {
                if (chess.isAttacked(newRow,5,1) || chess.isAttacked(newRow,6,1))
                {
                    cout << "Illegal move. No action taken. " << endl;
                    return false;
                }
                cout << "B ";
                white=false;
            }
            Bishop bishop(white);
            chess.set_field(newRow,6,*this);
            chess.set_field(newRow,5,bishop);
            chess.get_field(newRow,4)->setName("Free");
            chess.get_field(newRow,7)->setName("Free");
            chess.get_field(newRow,4)->unmoved=false;
            chess.get_field(newRow,7)->unmoved=false;
            cout << "King castle to B1. " << endl;
            return true;
        }
    }
    cout << "Illegal move. No action taken. " << endl;
    return false;
}

bool King::canAttack(int row, int col, int newRow, int newCol, Board& chess)
{
    if (row > newRow+1 || row < newRow-1 || col > newCol+1 || col < newCol-1)
    {
        return false;
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
