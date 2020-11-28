#pragma once

#include "utils.h"

#include <QObject>

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

    [[nodiscard]] int width() const noexcept;
    [[nodiscard]] int height() const noexcept;

    [[nodiscard]] cell_state state(const position& pos) const;
    [[nodiscard]] cell_state state(size_t index) const;
    void set_state(const position& pos, cell_state state);

    [[nodiscard]] bool inside_bounds(const position& pos) const;
    void generate_fruit();
    void clear();

signals:
    void data_changed(int);

private:
    size_t position_to_index(const position& pos) const;

    const int m_width,
              m_height;

    std::vector<cell_state> m_cells;
};
