#include "engine.h"

#include <iostream>

namespace
{

constexpr int number_snake_elements{6};
constexpr int board_width{20};
constexpr int board_height{13};

} // namespace

engine::engine() :
    m_board(board_width, board_height),
    m_snake(snake::direction::down)
{
    // initialize snake
    for (int i = 0; i < number_snake_elements; ++i)
        m_snake.push_front({i+2, 1});
    m_snake.move();

    // set snake elements on the board
    for (const auto& _element : m_snake.elements())
        m_board.set_state(_element, board::element_state::snake);

    m_board.generate_fruit();

    std::cout << m_board << std::endl;
}
