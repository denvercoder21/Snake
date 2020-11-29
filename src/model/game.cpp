#include "game.h"
#include "utils.h"

#include <algorithm>
#include <chrono>
#include <thread>

game_processor::game_processor(board& _board, snake& _snake, QObject *parent) :
    QObject(parent),
    m_board(_board),
    m_snake(_snake)
{
    reset_game();
}

void game_processor::process()
{
    while (!m_quit)
    {
        const auto start = std::chrono::high_resolution_clock::now();

        auto next = m_snake.next_element();

        // collison with walls
        if (!m_board.inside_bounds(next))
        {
            stop();
            continue;
        }

        // collision with snake itself
        const auto& snake = m_snake.elements();
        if (std::ranges::find(snake, next) != snake.end() && next != m_snake.tail())
        {
            stop();
            continue;
        }

        // path is clear, move snake
        if (m_board.state(next) == board::cell_state::fruit)
        {
            m_board.set_state(next, board::cell_state::snake);
            m_board.generate_fruit();
            m_snake.eat();
        }
        else
        {
            m_board.set_state(m_snake.tail(), board::cell_state::empty);
            m_board.set_state(next, board::cell_state::snake);
            m_snake.move();
        }

        sleep(start);
    }

    reset_game();
    emit game_over();
}

void game_processor::stop()
{
    m_quit = true;
}

void game_processor::sleep(const std::chrono::high_resolution_clock::time_point& start)
{
    using namespace std::chrono;

    const auto end = high_resolution_clock::now();
    const auto time_passed = duration_cast<nanoseconds>(end - start);
    const auto time_sleep = duration_cast<nanoseconds>(duration_cast<nanoseconds>(definitions::timestep) - time_passed);
    std::this_thread::sleep_for(nanoseconds(time_sleep));
}

void game_processor::reset_game()
{
    m_board.clear();
    m_snake.clear();

    initialize_snake();
    m_snake.set_direction(snake::direction::right);

    m_board.generate_fruit();
    m_quit = false;
}

void game_processor::initialize_snake()
{
    for (int i = 0; i < definitions::number_snake_elements; ++i)
    {
        const auto pos = position{i + 3, 4};
        m_snake.push_front(pos);
        m_board.set_state(pos, board::cell_state::snake);
    }
}

//----------------------------------------------------------------------------------------------------------------------

game::game(board& _board, snake& _snake, QObject* parent) :
    QObject(parent)
{
    m_processor = new game_processor(_board, _snake);
    m_processor->moveToThread(&m_game_thread);

    connect(&m_game_thread, &QThread::finished, m_processor, &QObject::deleteLater);
    connect(this, &game::start, m_processor, &game_processor::process);
    connect(m_processor, &game_processor::game_over, this, &game::gameOver);

    m_game_thread.start();
}

game::~game()
{
    m_processor->stop();
    m_game_thread.quit();
    m_game_thread.wait();
}

