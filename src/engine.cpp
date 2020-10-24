#include "engine.h"

#include <algorithm>
#include <iostream>
#include <iterator>

#include <chrono>
#include <thread>

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

    std::cout << m_board << "\n\n" << std::endl;
}

void engine::process()
{
    while (!m_quit)
    {
        auto next = m_snake.next_element();

        // collison with walls
        if (!m_board.inside_bounds(next))
        {
            m_quit = true;
            continue;
        }

        // collision with snake itself
        auto snake = m_snake.elements();
        if (std::ranges::find(snake, next) != snake.end() && next != m_snake.tail())
        {
            m_quit = true;
            continue;
        }

        m_board.set_state(next, board::element_state::snake);
        if (m_board.state(next) == board::element_state::fruit)
        {
            m_snake.eat();
            m_board.generate_fruit();
        }
        else
        {
            m_board.set_state(m_snake.tail(), board::element_state::empty);
            m_snake.move();
        }

        std::cout << m_board << "\n\n" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
