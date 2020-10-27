#pragma once

#include "board.h"
#include "snake.h"

#include <QObject>

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(QObject *parent = nullptr);

    Q_INVOKABLE void start() noexcept;

private:
    void process();

    board m_board;
    snake m_snake;

    bool m_quit{false};
};
