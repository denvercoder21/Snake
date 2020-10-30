#include "board_viewmodel.h"

#include "utils.h"

#include <QColor>

#include <iostream>

QColor getColor(board::cell c)
{
    switch (c)
    {
    case board::cell::empty:
        return Qt::gray;
    case board::cell::snake:
        return Qt::blue;
    case board::cell::fruit:
        return Qt::red;
    }

    return Qt::green;
}

board_viewmodel::board_viewmodel(const board& _board, QObject *parent) :
    QAbstractListModel(parent),
    m_board(_board)
{
    connect(&m_board, &board::data_changed, this, [this](const position& e){
        emit dataChanged(createIndex(e.x, e.y), createIndex(e.x, e.y));
    });

    connect(this, &board_viewmodel::dataChanged, this, [](const QModelIndex& tl, const QModelIndex& br){
        std::cout << "dataChanged: tl{" << tl.row() << ", " << tl.column() << "}\tbr{" << br.row() << ", " << br.column() << "}" << std::endl;
    });
}

QModelIndex board_viewmodel::index(int row, int column, const QModelIndex&) const
{
    return createIndex(row, column);
}

int board_viewmodel::rowCount(const QModelIndex&) const
{
    return m_board.width() * m_board.height();
}

int board_viewmodel::columnCount(const QModelIndex&) const
{
    return m_board.width();
}

QVariant board_viewmodel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() >= m_board.width() * m_board.height() || index.row() < 0)
        return QVariant();

    switch (role)
    {
    case CellState:
        return QVariant::fromValue(static_cast<board::cell>(m_board.state(index.row())));
    case Color:
        return getColor(static_cast<board::cell>(m_board.state(index.row())));
    }

    return QVariant{};
}
