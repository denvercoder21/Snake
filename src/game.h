#pragma once

#include "board.h"
#include "snake.h"

#include <QObject>
#include <thread>

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(board& _board, snake& _snake, QObject *parent = nullptr);

    Q_INVOKABLE void start() noexcept;

private:
    void process();

    board& m_board;
    snake& m_snake;

    bool m_quit{false};
    std::thread m_thread;
};
