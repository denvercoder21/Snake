#pragma once

#include "utils.h"

#include <QObject>

#include <iostream>
#include <vector>

class board : public QObject
{
    Q_OBJECT
public:
    enum class cell
    {
        empty = 0,
        snake,
        fruit
    };
    Q_ENUM(cell)

    board(int width, int height, QObject* parent = nullptr);

    int width() const noexcept;
    int height() const noexcept;

    [[nodiscard]] cell state(const element& _element) const;
    [[nodiscard]] cell state(size_t index) const;
    void set_state(const element& _element, cell state);

    [[nodiscard]] bool inside_bounds(const element& _element) const;

    void generate_fruit();
    void clear();

    size_t element_to_index(const element& _element) const;

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

signals:
    void data_changed(const element&);

private:
    const int m_width,
              m_height;

    std::vector<cell> m_cells;
};
