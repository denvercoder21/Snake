#pragma once

#include <list>
#include <utility>

#include <model/board_model.h>

namespace model
{

class snake_model
{
public:
  enum direction
  {
    right,
    left,
    up,
    down
  };

  snake_model(board_model& _board);

  void move();
  void eat();

  std::pair<int, int> next_limb();

  direction get_direction();
  void set_direction(direction);

  std::pair<unsigned, unsigned> tail();

private:
  std::pair<unsigned, unsigned> head();

  void push_front(std::pair<unsigned, unsigned> limb);
  void pop_front();
  void push_back(std::pair<unsigned, unsigned> limb);
  void pop_back();


  std::list<std::pair<unsigned, unsigned>> m_snake;
  board_model& m_board;
  direction m_direction;
};

} //model
