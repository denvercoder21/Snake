#include "snake_viewmodel.h"

namespace viewmodel
{

snake_viewmodel::snake_viewmodel(model::snake_model& snake_model) :
  m_snake_model(snake_model)
{
}

void snake_viewmodel::set_direction(Direction _direction)
{
  model::snake_model::direction new_direction;

  switch(_direction)
  {
    case Direction::Right:
      new_direction = model::snake_model::direction::right;
      break;

    case Direction::Left:
      new_direction = model::snake_model::direction::left;
      break;

    case Direction::Up:
      new_direction = model::snake_model::direction::up;
      break;

    case Direction::Down:
      new_direction = model::snake_model::direction::down;
      break;
  };

  m_snake_model.set_direction(new_direction);
}

} //viewmodel
