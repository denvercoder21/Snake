#pragma once

#include "utils.h"

#include <iostream>
#include <vector>

class board
{
public:
    enum class element_state
    {
        empty = 0,
        snake,
        fruit
    };

    board(int width, int height);

    element_state state(const element& _element) const;
    void set_state(const element& _element, element_state state);

    bool inside_bounds(const element& _element) const;

    void generate_fruit();

    friend std::ostream& operator<<(std::ostream& str, board::element_state state)
    {
        switch (state)
        {
        [[likely]]
        case board::element_state::empty:
            str << " - ";
            break;
        case board::element_state::snake:
            str << " # ";
            break;
        [[unlikely]]
        case board::element_state::fruit:
            str << " o ";
            break;
        }
        return str;
    }

    friend std::ostream& operator<<(std::ostream& str, const board& b)
    {
        for (int i = 0; i < b.m_height; ++i)
        {
            for (int j = 0; j < b.m_width; ++j)
                str << b.state({j, i});
            str << "\n";
        }
        return str;
    }

private:
    size_t element_to_index(const element& _element) const;

    int m_width,
        m_height;

    std::vector<element_state> m_elements;
};
