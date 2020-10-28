#pragma once

#include "board.h"

#include <QAbstractListModel>

class board_viewmodel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum State
    {
        Empty,
        Snake,
        Fruit
    };
    Q_ENUM(State)

    board_viewmodel(const board& _board, QObject *parent = nullptr);

    QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
    const board& m_board;
};
