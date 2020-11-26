#pragma once

#include "utils.h"

#include <list>

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

    void push_front(const position& pos);

    position tail() const;
    position next_element() const;
    std::list<position> elements() const;

    void set_direction(direction _direction);

    void clear();

private:
    position head() const;

    void push_back(const position& pos);

    void pop_front();
    void pop_back();

    direction m_direction;
    std::list<position> m_snake;
};
