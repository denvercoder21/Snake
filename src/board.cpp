#include "board.h"

#include <algorithm>
#include <iostream>
#include <ranges>

board::board(int width, int height, QObject* parent) :
    QObject(parent),
    m_width(width),
    m_height(height),
    m_cells(width * height, cell::empty)
{
}

int board::width() const noexcept
{
    return m_width;
}

int board::height() const noexcept
{
    return m_height;
}

board::cell board::state(const element &_element) const
{
    return state(element_to_index(_element));
}

board::cell board::state(size_t index) const
{
    try
    {
        return m_cells.at(index);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        return cell::empty;
    }
}

void board::set_state(const element& _element, board::cell state)
{
    try
    {
        m_cells.at(element_to_index(_element)) = state;
        emit data_changed(_element);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

bool board::inside_bounds(const element &_element) const
{
    return     _element.x >= 0
            && _element.x < m_width
            && _element.y >= 0
            && _element.y < m_height;
}

void board::generate_fruit()
{
    auto empty = [](const cell c){
        return c == cell::empty;
    };

    auto rndm_empty = utils::select_randomly(m_cells | std::views::filter(empty));
    *rndm_empty = cell::fruit;
}

void board::clear()
{
    std::ranges::fill(m_cells, cell::empty);
}

size_t board::element_to_index(const element &_element) const
{
    return static_cast<size_t>(_element.y * m_width + _element.x);
}
