#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED
#include "Figure.h"

class Knight : public Figure
{
public:
    Knight(FigureColor = 1);
	void move();
};

#endif // KNIGHT_H_INCLUDED
