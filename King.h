#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED
#include "Figure.h"

class King : public Figure
{
public:
    King(FigureColor = 1);
	void move();
};

#endif // KING_H_INCLUDED
