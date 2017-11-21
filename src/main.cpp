#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

#include <model/game_model.h>
#include <viewmodel/board_viewmodel.h>
#include <viewmodel/snake_viewmodel.h>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  qRegisterMetaType<QVector<int> >("QVector<int>");
  qmlRegisterUncreatableType<viewmodel::snake_viewmodel>("Snake.Direction", 1, 0, "Direction", "Represents a direction a snake can head in");

  model::game_model game;
  viewmodel::board_viewmodel board(game.get_board());
  viewmodel::snake_viewmodel snake(game.get_snake());
  QQmlApplicationEngine engine;
  QQmlContext *ctxt = engine.rootContext();

  ctxt->setContextProperty("board", &board);
  ctxt->setContextProperty("snake", &snake);

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
