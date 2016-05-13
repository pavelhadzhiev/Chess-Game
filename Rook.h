#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED
#include "Figure.h"

class Rook : public Figure
{
public:
    Rook(FigureColor = 1);
	void move();
};

#endif // ROOK_H_INCLUDED
