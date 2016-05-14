#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED
#include "Figure.h"
#include "Board.h"

class King : public Figure
{
public:
    King(FigureColor = 1);
	void move(int, int, int, int, Board&);
};

#endif // KING_H_INCLUDED
