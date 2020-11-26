#include "snake_viewmodel.h"

snake_viewmodel::snake_viewmodel(snake& _snake, QObject *parent) :
    QObject(parent),
    m_snake(_snake)
{
}

void snake_viewmodel::setDirection(Direction direction) const noexcept
{
    switch (direction)
    {
    case snake_viewmodel::Direction::Left:
        m_snake.set_direction(snake::direction::left);
        break;
    case snake_viewmodel::Direction::Right:
        m_snake.set_direction(snake::direction::right);
        break;
    case snake_viewmodel::Direction::Up:
        m_snake.set_direction(snake::direction::up);
        break;
    case snake_viewmodel::Direction::Down:
        m_snake.set_direction(snake::direction::down);
        break;
    }
}
