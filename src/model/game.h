#pragma once

#include "board.h"
#include "snake.h"

#include <QObject>
#include <QThread>

#include <chrono>

class game_processor : public QObject
{
    Q_OBJECT
public:
    explicit game_processor(board& _board, snake& _snake, QObject *parent = nullptr);
    void process();
    void stop();

signals:
    void game_over();

private:
    void sleep(const std::chrono::high_resolution_clock::time_point& start);

    board& m_board;
    snake& m_snake;

    bool m_quit{false};
};

//----------------------------------------------------------------------------------------------------------------------

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(board& _board, snake& _snake, QObject *parent = nullptr);
    ~game();

    Q_INVOKABLE void start() noexcept;

signals:
    void gameOver();

private:
    game_processor* m_processor;
    QThread m_game_thread;
};

