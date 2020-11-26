#pragma once

#include "model/snake.h"

#include <QObject>

class snake_viewmodel : public QObject
{
    Q_OBJECT
public:
    enum class Direction
    {
        Left = 0,
        Right,
        Up,
        Down
    };
    Q_ENUM(Direction)

    explicit snake_viewmodel(snake& _snake, QObject *parent = nullptr);

    Q_INVOKABLE void setDirection(Direction direction) const noexcept;

private:
    snake& m_snake;
};
