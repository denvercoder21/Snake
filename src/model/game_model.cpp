#include <chrono>
#include <thread>

#include "game_model.h"

namespace model
{

game_model::game_model() :
  m_board(21, 12),
  m_snake(m_board)
{
  std::thread looper(&game_model::loop, this);
  looper.detach();
}

//----------------------------------------------------------------------------------------------------------------------

board_model& game_model::get_board()
{
  return m_board;
}

//----------------------------------------------------------------------------------------------------------------------

snake_model& game_model::get_snake()
{
  return m_snake;
}

//----------------------------------------------------------------------------------------------------------------------

void game_model::loop()
{
  while(true)
  {
    if(collision())
      break;

    if(hit_fruit())
    {
      m_snake.eat();
      m_board.generate_fruit();
      continue;
    }

    m_snake.move();

    std::this_thread::sleep_for(std::chrono::milliseconds(222));
  }

  m_board.clear();
}

//----------------------------------------------------------------------------------------------------------------------

bool game_model::collision()
{
  auto next_limb = m_snake.next_limb();
  return hit_snake(next_limb) || hit_wall(next_limb);
}

//----------------------------------------------------------------------------------------------------------------------

bool game_model::hit_fruit()
{
  auto next_limb = m_snake.next_limb();
  auto fruit     = m_board.get_fruit();
  return (next_limb.first == (int) fruit.first && next_limb.second == (int) fruit.second);
}

//----------------------------------------------------------------------------------------------------------------------

bool game_model::hit_snake(std::pair<int, int> limb)
{
  auto _tail = m_snake.tail();
  if(limb.first == (int) _tail.first && limb.second == (int) _tail.second)
    return false;

  return (m_board.get_state(limb.first, limb.second) == board_model::state::snake);
}

//----------------------------------------------------------------------------------------------------------------------

bool game_model::hit_wall(std::pair<int, int> limb)
{
  return !m_board.within_boundaries(limb);
}

} //model
