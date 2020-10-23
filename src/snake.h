#pragma once

#include "utils.h"

#include <list>
#include <utility>

class snake
{
public:
    enum class direction
    {
        left = 0,
        right,
        up,
        down
    };

    snake(direction _direction);

    void move();

    void push_front(const element& _element);

    std::list<element> elements() const;

private:
    element head() const;
    element tail() const;

    void push_back(const element& _element);

    void pop_front();
    void pop_back();

    element next_element() const;

    direction m_direction;
    std::list<element> m_snake;
};
