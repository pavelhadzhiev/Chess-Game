#include <iostream>
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

using namespace std;

int main()
{
    Board chess;
    chess.start();
    Pawn black_pawn(0);
    Pawn white_pawn;
    chess.set_field(5,5,black_pawn);
    chess.get_field(6,5)->setName("Free");
    chess.set_field(3,4,white_pawn);
    chess.get_field(1,4)->setName("Free");
    chess.set_field(2,6,white_pawn);
    chess.get_field(1,6)->setName("Free");
    chess.print_board();
    return 0;
}
