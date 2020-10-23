#include "snake.h"

snake::snake(snake::direction _direction) :
    m_direction(_direction)
{
}

void snake::move()
{
    auto next = next_element();

    // order matters in case that the next element is our own tail
    pop_back();
    push_front(next);
}

element snake::head() const
{
    return m_snake.front();
}

element snake::tail() const
{
    return m_snake.back();
}

void snake::push_front(const element &_element)
{
    m_snake.push_front(_element);
}

std::list<element> snake::elements() const
{
    return m_snake;
}

void snake::push_back(const element &_element)
{
    m_snake.push_back(_element);
}

void snake::pop_front()
{
    m_snake.pop_front();
}

void snake::pop_back()
{
    m_snake.pop_back();
}

element snake::next_element() const
{
    auto _head = head();

    switch (m_direction)
    {
    case direction::left:
        _head.x--;
        break;

    case direction::right:
        _head.x++;
        break;

    case direction::up:
        _head.y--;
        break;

    case direction::down:
        _head.y++;
        break;
    }

    return _head;
}
