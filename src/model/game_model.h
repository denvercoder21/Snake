#pragma once

#include <model/board_model.h>
#include <model/snake_model.h>

namespace model
{

class game_model
{
public:
  game_model();

  board_model& get_board();
  snake_model& get_snake();

private:
  void loop();
  void generate_fruit();

  bool collision();
  bool hit_fruit();
  bool hit_snake(std::pair<int, int> limb);
  bool hit_wall(std::pair<int, int> limb);

  snake_model::direction get_random_direction();


  board_model m_board;
  snake_model m_snake;
};

} //model

