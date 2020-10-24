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
    void eat();

    void push_front(const element& _element);


    element tail() const;
    element next_element() const;
    std::list<element> elements() const;

    void set_direction(direction _direction);

private:
    element head() const;

    void push_back(const element& _element);

    void pop_front();
    void pop_back();

    direction m_direction;
    std::list<element> m_snake;
};
