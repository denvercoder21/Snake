#include "board.h"

#include <iostream>
#include <ranges>

board::board(int width, int height) :
    m_width(width),
    m_height(height),
    m_elements(width * height, element_state::empty)
{
}

board::element_state board::state(const element &_element) const
{
    try
    {
        return m_elements.at(element_to_index(_element));
    }  catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        return element_state::empty;
    }
}

void board::set_state(const element& _element, board::element_state state)
{
    try
    {
        m_elements.at(element_to_index(_element)) = state;
    }  catch (const std::out_of_range& e)
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
    auto empty_cells = [](const element_state c){ return c == element_state::empty; };
    auto rndm_empty = select_randomly(m_elements | std::views::filter(empty_cells));
    *rndm_empty = element_state::fruit;
}

size_t board::element_to_index(const element &_element) const
{
    return static_cast<size_t>(_element.y * m_width + _element.x);
}
