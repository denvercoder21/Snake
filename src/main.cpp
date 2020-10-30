#include "board.h"
#include "board_viewmodel.h"
#include "game.h"
#include "game_viewmodel.h"
#include "snake.h"
#include "utils.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);    auto board_logic = board{definitions::board_width, definitions::board_height};

    qRegisterMetaType<position>("position");

    auto board_view = board_viewmodel{board_logic};

    auto snake_logic = snake{snake::direction::down};

    auto game_logic = game{board_logic, snake_logic};
    auto game_view = game_viewmodel{game_logic};

    QQmlApplicationEngine engine{};

    engine.rootContext()->setContextProperty("Game", &game_view);
    engine.rootContext()->setContextProperty("BoardModel", &board_view);

    engine.load("qrc:/main.qml");

    return app.exec();
}
