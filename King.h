#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED
#include "Figure.h"
#include "Board.h"
#include "Bishop.h"

class King : public Figure
{
public:
    King(FigureColor = 1);
	bool move(int, int, int, int, Board&);
	bool canAttack(int, int, int, int, Board&);
	bool castle(int, int, Board&);
};

#endif // KING_H_INCLUDED
