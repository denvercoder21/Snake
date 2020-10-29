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
    connect(&m_board, &board::data_changed, this, [this](const element& e){
        emit dataChanged(createIndex(e.x, e.y), createIndex(e.x, e.y));
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

    std::cout << "before switch, role: " << role << std::endl;

    switch (role)
    {
    case CellState:
        std::cout << "CellState" << std::endl;
        return QVariant::fromValue(static_cast<board::cell>(m_board.state(index.row())));
    case Color:
        std::cout << "Color" << std::endl;
        return getColor(static_cast<board::cell>(m_board.state(index.row())));
    }

    std::cout << "after switch" << std::endl;

    return QVariant{};

//    auto state = static_cast<board_viewmodel::State>(m_board.state(index.row()));
//    return qVariantFromValue(state);
}
