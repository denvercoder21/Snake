#pragma once

#include "board.h"
#include "snake.h"
#include "utils.h"

class engine
{
public:
    engine();

private:
    board m_board;
    snake m_snake;
};
