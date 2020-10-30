#pragma once

#include "utils.h"

#include <QObject>

#include <iostream>
#include <vector>

class board : public QObject
{
    Q_OBJECT
public:
    enum class cell_state
    {
        empty = 0,
        snake,
        fruit
    };

    board(int width, int height, QObject* parent = nullptr);

    int width() const noexcept;
    int height() const noexcept;

    [[nodiscard]] cell_state state(const position& pos) const;
    [[nodiscard]] cell_state state(size_t index) const;
    void set_state(const position& pos, cell_state state);

    [[nodiscard]] bool inside_bounds(const position& pos) const;

    void generate_fruit();
    void clear();

    size_t element_to_index(const position& pos) const;

    friend std::ostream& operator<<(std::ostream& str, board::cell_state state)
    {
        switch (state)
        {
        [[likely]]
        case board::cell_state::empty:
            str << " - ";
            break;
        case board::cell_state::snake:
            str << " # ";
            break;
        [[unlikely]]
        case board::cell_state::fruit:
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

signals:
    void data_changed(const position&);

private:
    const int m_width,
              m_height;

    std::vector<cell_state> m_cells;
};
