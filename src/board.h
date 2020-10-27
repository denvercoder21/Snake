#pragma once

#include "utils.h"

#include <iostream>
#include <vector>

class board
{
public:
    enum class cell
    {
        empty = 0,
        snake,
        fruit
    };

    board(int width, int height);

    [[nodiscard]] cell state(const element& _element) const;
    void set_state(const element& _element, cell state);

    [[nodiscard]] bool inside_bounds(const element& _element) const;

    void generate_fruit();
    void clear();

    friend std::ostream& operator<<(std::ostream& str, board::cell state)
    {
        switch (state)
        {
        [[likely]]
        case board::cell::empty:
            str << " - ";
            break;
        case board::cell::snake:
            str << " # ";
            break;
        [[unlikely]]
        case board::cell::fruit:
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

    const int m_width,
              m_height;

    std::vector<cell> m_cells;
};
