#include "engine.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <functional>
#include <thread>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine("qrc:/main.qml");

    class engine game;
    std::thread(std::bind(&engine::process, &game)).detach();

    return app.exec();
}
