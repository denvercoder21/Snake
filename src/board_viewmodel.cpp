#include "board_viewmodel.h"

#include "utils.h"

#include <iostream>

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

    if(role != Qt::DisplayRole)
        return QVariant();

    if(index.row() >= m_board.width() * m_board.height() || index.row() < 0)
        return QVariant();

    auto state = static_cast<board_viewmodel::State>(m_board.state(index.row()));
    return qVariantFromValue(state);
}
