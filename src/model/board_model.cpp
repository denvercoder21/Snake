#include <cstdlib>
#include <ctime>

#include "board_model.h"

namespace model
{

board_model::board_model(unsigned width, unsigned height) :
  m_board(width, std::vector<board_model::state>(height, board_model::state::empty)),
  m_width(width),
  m_height(height),
  m_fruit(std::make_pair(10, 6))
{
  std::srand(std::time(0));
  set_state(m_fruit.first, m_fruit.second, board_model::state::fruit);
}

//----------------------------------------------------------------------------------------------------------------------

void board_model::clear()
{
  for(unsigned x = 0; x < m_width; ++x)
    for(unsigned y = 0; y < m_height; ++y)
      set_state(x, y, board_model::state::empty);
}

//----------------------------------------------------------------------------------------------------------------------

unsigned board_model::width() const
{
  return m_width;
}

//----------------------------------------------------------------------------------------------------------------------

unsigned board_model::height() const
{
  return m_height;
}

//----------------------------------------------------------------------------------------------------------------------

std::pair<unsigned, unsigned> board_model::get_fruit() const
{
  return m_fruit;
}

//----------------------------------------------------------------------------------------------------------------------

bool board_model::within_boundaries(std::pair<int, int> cell) const
{
  if(cell.first >= (int) m_width || cell.first < 0)
    return false;

  if(cell.second >= (int) m_height || cell.second < 0)
    return false;

  return true;
}

//----------------------------------------------------------------------------------------------------------------------

board_model::state board_model::get_state(unsigned x, unsigned y) const
{
  if((size_t) x >= m_board.size())
    return board_model::state::empty;

  if((size_t) y >= m_board.at(0).size())
    return board_model::state::empty;

  return m_board.at(x).at(y);
}

//----------------------------------------------------------------------------------------------------------------------

void board_model::set_state(unsigned x, unsigned y, board_model::state state)
{
  if(get_state(x, y) == state)
    return;

  m_board.at(x).at(y) = state;
}

//----------------------------------------------------------------------------------------------------------------------

void board_model::generate_fruit()
{
  do
  {
    m_fruit.first  = std::rand() % (int) width();
    m_fruit.second = std::rand() % (int) height();
  }
  while(get_state(m_fruit.first, m_fruit.second) == board_model::state::snake);

  set_state(m_fruit.first, m_fruit.second, board_model::state::fruit);
}

} //model
