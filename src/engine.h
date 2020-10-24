#pragma once

#include "board.h"
#include "snake.h"
#include "utils.h"

class engine
{
public:
    engine();

    void process();

private:
    board m_board;
    snake m_snake;

    bool m_quit{false};
};
