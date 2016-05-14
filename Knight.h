#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED
#include "Figure.h"
#include "Board.h"

class Knight : public Figure
{
public:
    Knight(FigureColor = 1);
	void move(int, int, int, int, Board&);
};

#endif // KNIGHT_H_INCLUDED
