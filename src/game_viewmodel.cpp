#include "game_viewmodel.h"

game_viewmodel::game_viewmodel(game &_game, QObject *parent) :
    QObject(parent),
    m_game(_game)
{
}

void game_viewmodel::start() noexcept
{
    m_game.start();
}
