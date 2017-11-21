#include "board_viewmodel.h"

namespace viewmodel
{

board_viewmodel::board_viewmodel(model::board_model& board) :
  m_board(board)
{
}

//----------------------------------------------------------------------------------------------------------------------

QModelIndex board_viewmodel::index(int row, int column, const QModelIndex&) const
{
  if(row >= (int) m_board.width() || row < 0)
    return QModelIndex();

  if(column >= (int) m_board.height() || column < 0)
    return QModelIndex();

  return createIndex(row, column);
}

//----------------------------------------------------------------------------------------------------------------------

QModelIndex board_viewmodel::parent(const QModelIndex& index) const
{
  if(index.row() >= (int) m_board.width() || index.row() < 0)
    return QModelIndex();

  if(index.column() >= (int) m_board.height() || index.column() < 0)
    return QModelIndex();

  return createIndex(index.row(), index.column());
}

//----------------------------------------------------------------------------------------------------------------------

int board_viewmodel::rowCount(const QModelIndex&) const
{
  return m_board.height();
}

//----------------------------------------------------------------------------------------------------------------------

int board_viewmodel::columnCount(const QModelIndex&) const
{
  return m_board.height();
}

//----------------------------------------------------------------------------------------------------------------------

QVariant board_viewmodel::data(const QModelIndex& index, int role) const
{
  if(!index.isValid())
    return QVariant();

  if(role != Qt::DisplayRole)
    return QVariant();

  if(index.row() >= (int) m_board.width() || index.row() < 0)
    return QVariant();

  if(index.column() >= (int) m_board.height() || index.column() < 0)
    return QVariant();

  auto state = static_cast<board_viewmodel::State>(m_board.get_state(index.row(), index.column()));
  return qVariantFromValue(state);
}

} //viewmodel
