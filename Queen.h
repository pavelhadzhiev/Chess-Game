#ifndef QUEEN_H
#define QUEEN_H
#include "Figure.h"

class Queen : public Figure
{
public:
    Queen(FigureColor = 1);
	void move();
};

#endif // !QUEEN_H
