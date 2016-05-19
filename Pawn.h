#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED
#include "Figure.h"
#include "Board.h"

class Pawn : public Figure
{
public:
    Pawn(FigureColor = 1);
	bool move(int, int, int, int, Board&);
	bool canAttack(int, int, int, int, Board&);
};

#endif // PAWN_H_INCLUDED
