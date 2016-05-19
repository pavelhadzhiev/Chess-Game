#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED
#include "Figure.h"
#include "Board.h"

class Rook : public Figure
{
public:
    Rook(FigureColor = 1);
	bool move(int, int, int, int, Board&);
	bool canAttack(int, int, int, int, Board&);
};

#endif // ROOK_H_INCLUDED
