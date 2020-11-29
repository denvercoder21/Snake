#include "model/board.h"
#include "model/game.h"
#include "model/snake.h"

#include "viewmodel/board_viewmodel.h"
#include "viewmodel/snake_viewmodel.h"

#include "utils.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qRegisterMetaType<position>("position");
    qmlRegisterUncreatableType<board_viewmodel>("Board.CellState", 1, 0, "CellState", "State a cell in the game board is in");
    qmlRegisterUncreatableType<snake_viewmodel>("Snake.Direction", 1, 0, "Direction", "Direction a snake can head in");

    auto board_logic = board{definitions::board_width, definitions::board_height};
    auto snake_logic = snake{snake::direction::right};
    auto game_logic = game{board_logic, snake_logic};

    auto board_view = board_viewmodel{board_logic};
    auto snake_view = snake_viewmodel{snake_logic};

    QQmlApplicationEngine engine{};

    engine.rootContext()->setContextProperty("Game", &game_logic);
    engine.rootContext()->setContextProperty("BoardModel", &board_view);
    engine.rootContext()->setContextProperty("Snake", &snake_view);

    engine.load("qrc:/main.qml");

    return app.exec();
}
