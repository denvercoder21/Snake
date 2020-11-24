#include "board_viewmodel.h"

#include "utils.h"

board_viewmodel::board_viewmodel(const board& _board, QObject *parent) :
    QAbstractListModel(parent),
    m_board(_board)
{
    connect(&m_board, &board::data_changed, this, [this](const position& /*e*/){
//        emit dataChanged(createIndex(e.x, e.y), createIndex(e.x, e.y), {Qt::DisplayRole});
        emit dataChanged(createIndex(0, 0), createIndex(m_board.width(), m_board.height()), {Qt::DisplayRole});
    });

    connect(this, &QAbstractListModel::dataChanged, this, [](const QModelIndex& tl,
                                                             const QModelIndex& br,
                                                             const QVector<int>& r){
        std::cout << "data changed at:\n\tTL (x: " << tl.column() << ", y: " << tl.row() << ")\n\tBR (x: " << br.column() << ", y: " << br.row() << ")\n\tR: " << r.first() << std::endl;
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

    if (role != Qt::DisplayRole)
        return QVariant();

    return QVariant::fromValue(static_cast<int>(m_board.state(index.row())));
}
