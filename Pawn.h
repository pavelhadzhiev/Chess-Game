#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED
#include "Figure.h"

class Pawn : public Figure
{
public:
    Pawn(FigureColor = 1);
	void move();
};

#endif // PAWN_H_INCLUDED
