#pragma once

#include <QAbstractItemModel>

#include <model/board_model.h>

namespace viewmodel
{

class board_viewmodel : public QAbstractItemModel
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

  board_viewmodel(model::board_model& board);

  QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
  QModelIndex parent(const QModelIndex& index) const;
  int rowCount(const QModelIndex& parent = QModelIndex()) const;
  int columnCount(const QModelIndex& parent = QModelIndex()) const;
  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

private:
  model::board_model& m_board;
};

} //viewmodel
