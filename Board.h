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

    void print_board()const;
    void print_taken()const;

    void start();
};

#endif // BOARD_H_INCLUDED
