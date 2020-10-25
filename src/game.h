#pragma once

#include "board.h"
#include "snake.h"

class game
{
public:
    game();

    void start();
    void restart();
    void reset();

private:

    void process();
    board m_board;
    snake m_snake;

    bool m_quit{false};
};
