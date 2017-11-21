#include "snake_model.h"

namespace model
{

snake_model::snake_model(board_model& _board) :
  m_board(_board),
  m_direction(snake_model::direction::right)
{
  for(int x = 0; x < 6; ++x)
    push_front(std::make_pair(x, 6));
}

//----------------------------------------------------------------------------------------------------------------------

void snake_model::move()
{
  auto head = next_limb();

  //order matters for case that next limb is our own tail
  pop_back();
  push_front(head);
}

//----------------------------------------------------------------------------------------------------------------------

void snake_model::eat()
{
  auto _head = head();
  m_board.set_state(_head.first, _head.second, board_model::state::snake);

  _head = next_limb();
  push_back(_head);
}

//----------------------------------------------------------------------------------------------------------------------

std::pair<int, int> snake_model::next_limb()
{
  std::pair<int, int> head = snake_model::head();

  switch(m_direction)
  {
    case snake_model::direction::right:
      head.first++;
      break;

    case snake_model::direction::left:
      head.first--;
      break;

    case snake_model::direction::up:
      head.second--;
      break;

    case snake_model::direction::down:
      head.second++;
      break;
  };

  return head;
}

//----------------------------------------------------------------------------------------------------------------------

snake_model::direction snake_model::get_direction()
{
  return m_direction;
}

//----------------------------------------------------------------------------------------------------------------------

void snake_model::set_direction(snake_model::direction direction)
{
  if(m_direction == direction)
    return;

  if(m_direction == snake_model::direction::right && direction == snake_model::direction::left)
    return;

  if(m_direction == snake_model::direction::left && direction == snake_model::direction::right)
    return;

  if(m_direction == snake_model::direction::up && direction == snake_model::direction::down)
    return;

  if(m_direction == snake_model::direction::down && direction == snake_model::direction::up)
    return;

  m_direction = direction;
}

//----------------------------------------------------------------------------------------------------------------------

std::pair<unsigned, unsigned> snake_model::head()
{
  return m_snake.front();
}

//----------------------------------------------------------------------------------------------------------------------

std::pair<unsigned, unsigned> snake_model::tail()
{
  return m_snake.back();
}

//----------------------------------------------------------------------------------------------------------------------

void snake_model::push_front(std::pair<unsigned, unsigned> limb)
{
  m_snake.push_front(limb);
  m_board.set_state(limb.first, limb.second, board_model::state::snake);
}

//----------------------------------------------------------------------------------------------------------------------

void snake_model::pop_front()
{
  auto _head = head();
  m_board.set_state(_head.first, _head.second, board_model::state::empty);

  m_snake.pop_front();
}

//----------------------------------------------------------------------------------------------------------------------

void snake_model::push_back(std::pair<unsigned, unsigned> limb)
{
  m_snake.push_back(limb);
  m_board.set_state(limb.first, limb.second, board_model::state::snake);
}

//----------------------------------------------------------------------------------------------------------------------

void snake_model::pop_back()
{
  auto _tail = tail();
  m_board.set_state(_tail.first, _tail.second, board_model::state::empty);
  m_snake.pop_back();
}

} //model
