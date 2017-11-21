#pragma once

#include <vector>

namespace model
{

class board_model
{
public:
  enum state
  {
    empty,
    snake,
    fruit
  };

  board_model(unsigned width, unsigned height);

  state get_state(unsigned x, unsigned y) const;
  void  set_state(unsigned x, unsigned y, state state);

  unsigned width() const;
  unsigned height() const;
  std::pair<unsigned, unsigned> get_fruit() const;

  void generate_fruit();
  bool within_boundaries(std::pair<int, int> cell) const;

  void clear();

private:
  std::vector<std::vector<state>> m_board;
  unsigned  m_width = 0,
           m_height = 0;
  std::pair<unsigned, unsigned> m_fruit;
};

} //model
