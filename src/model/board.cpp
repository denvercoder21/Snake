#include "board.h"

#include <algorithm>
#include <iostream>
//#include <ranges>

board::board(int width, int height, QObject* parent) :
    QObject(parent),
    m_width(width),
    m_height(height),
    m_cells(width * height, cell_state::empty)
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

board::cell_state board::state(const position& pos) const
{
    return state(position_to_index(pos));
}

board::cell_state board::state(size_t index) const
{
    try
    {
        return m_cells.at(index);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        return cell_state::empty;
    }
}

void board::set_state(const position& pos, board::cell_state state)
{
    try
    {
        const auto index = position_to_index(pos);
        m_cells.at(index) = state;
        emit data_changed(static_cast<int>(index));
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

bool board::inside_bounds(const position& pos) const
{
    return     pos.x >= 0
            && pos.x < m_width
            && pos.y >= 0
            && pos.y < m_height;
}

void board::generate_fruit()
{
    auto empty = [](const cell_state c){
        return c == cell_state::empty;
    };

    auto rndm_empty = utils::select_randomly(m_cells | std::views::filter(empty));
    *rndm_empty = cell_state::fruit;
}

void board::clear()
{
    std::ranges::fill(m_cells, cell_state::empty);
    emit data_changed(position_to_index({width(), height()}));
}

size_t board::position_to_index(const position& pos) const
{
    return static_cast<size_t>(pos.y * m_width + pos.x);
}
