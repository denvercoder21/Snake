#include "game.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <functional>
#include <thread>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine("qrc:/main.qml");

    auto logic = game{};

    return app.exec();
}
