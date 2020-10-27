#include "game.h"

#include <algorithm>
#include <iostream>

namespace
{

constexpr int number_snake_elements{6};
constexpr int board_width{20};
constexpr int board_height{13};

} // namespace

game::game(QObject* parent) :
    QObject(parent),
    m_board(board_width, board_height),
    m_snake(snake::direction::down)
{
    // initialize snake
    for (int i = 0; i < number_snake_elements; ++i)
        m_snake.push_front({i+2, 1});
    m_snake.move();

    // set snake elements on the board
    for (const auto& _element : m_snake.elements())
        m_board.set_state(_element, board::cell::snake);

    m_board.generate_fruit();
}

void game::start() noexcept
{
    std::cout << "game started" << std::endl;
//    process();
}

void game::process()
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
        const auto& snake = m_snake.elements();
        if (std::ranges::find(snake, next) != snake.end() && next != m_snake.tail())
        {
            m_quit = true;
            continue;
        }

        // path is clear, move snake
        m_board.set_state(next, board::cell::snake);
        if (m_board.state(next) == board::cell::fruit)
        {
            m_snake.eat();
            m_board.generate_fruit();
        }
        else
        {
            m_board.set_state(m_snake.tail(), board::cell::empty);
            m_snake.move();
        }
    }
}
