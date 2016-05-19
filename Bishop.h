#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED
#include "Figure.h"
#include "Board.h"

class Bishop : public Figure
{
public:
    Bishop(FigureColor = 1);
	bool move(int, int, int, int, Board&);
	bool canAttack(int, int, int, int, Board&);
};

#endif // BISHOP_H_INCLUDED
