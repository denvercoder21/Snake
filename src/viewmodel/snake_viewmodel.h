#pragma once

#include <QQmlEngine>

#include <model/snake_model.h>

namespace viewmodel
{

class snake_viewmodel : public QObject
{
  Q_OBJECT

public:
  enum Direction
  {
    Right,
    Left,
    Up,
    Down
  };
  Q_ENUM(Direction)

  snake_viewmodel(model::snake_model& snake_model);

  Q_INVOKABLE void set_direction(Direction);

private:
  model::snake_model& m_snake_model;
};

} //viewmodel
