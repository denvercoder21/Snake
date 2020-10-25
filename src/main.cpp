#include "game.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <functional>
#include <thread>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine("qrc:/main.qml");

    auto snake = game{};

    return app.exec();
}
