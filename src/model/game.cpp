#include "game.h"
#include "utils.h"

#include <algorithm>
#include <iostream>

game_processor::game_processor(board& _board, snake& _snake, QObject *parent) :
    QObject(parent),
    m_board(_board),
    m_snake(_snake)
{
    // initialize snake
    for (int i = 0; i < definitions::number_snake_elements; ++i)
        m_snake.push_front({i+2, 1});
    m_snake.move();

    // set snake elements on the board
    for (const auto& pos : m_snake.elements())
        m_board.set_state(pos, board::cell_state::snake);

    m_board.generate_fruit();
}

void game_processor::process()
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
        m_board.set_state(next, board::cell_state::snake);
        if (m_board.state(next) == board::cell_state::fruit)
        {
            m_snake.eat();
            m_board.generate_fruit();
        }
        else
        {
            m_board.set_state(m_snake.tail(), board::cell_state::empty);
            m_snake.move();
        }

        std::cout << m_board << std::endl;
        QThread::msleep(3000);
    }
}

game::game(board& _board, snake& _snake, QObject* parent) :
    QObject(parent),
    m_processor(_board, _snake)
{
    m_processor.moveToThread(&m_game_thread);
    connect(&m_game_thread, &QThread::started, &m_processor, &game_processor::process);
    connect(&m_game_thread, &QThread::finished, &m_processor, &QObject::deleteLater);
}

game::~game()
{
    m_game_thread.quit();
    m_game_thread.wait();
}

void game::start() noexcept
{
    m_game_thread.start();
}

