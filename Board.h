#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Figure.h"

class Board
{
    Figure board[8][12];
public:
    Board();

    void set_field(int, int, Figure);
    Figure* get_field(int, int);

    bool move(int, int, int, int);

    void announce(int, int, int, int);
    void take(int, int);
    bool isFree(int, int);
    bool isAttacked(int, int, bool);

    void print_board()const;
    void print_taken()const;

    void start();

    void game();
    bool ended();
};

#endif // BOARD_H_INCLUDED
