#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED
#include "Figure.h"
#include "Board.h"

class Bishop : public Figure
{
public:
    Bishop(FigureColor = 1);
	void move(int, int, int, int, Board&);
};

#endif // BISHOP_H_INCLUDED
