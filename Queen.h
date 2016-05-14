#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED
#include "Figure.h"
#include "Board.h"

class Queen : public Figure
{
public:
    Queen(FigureColor = 1);
	void move(int, int, int, int, Board&);
};

#endif // !QUEEN_H
