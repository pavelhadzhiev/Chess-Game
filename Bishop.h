#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED
#include "Figure.h"

class Bishop : public Figure
{
public:
    Bishop(FigureColor = 1);
	void move();
};

#endif // BISHOP_H_INCLUDED
