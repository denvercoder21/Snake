#pragma once

#include "model/game.h"

#include <QObject>

class game_viewmodel : public QObject
{
    Q_OBJECT
public:
    explicit game_viewmodel(game& _game, QObject *parent = nullptr);

    Q_INVOKABLE void start() noexcept;

private:
    game& m_game;
};
