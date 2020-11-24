#pragma once

#include <QObject>
#include <QThread>

class game_thread : public QObject
{
    Q_OBJECT
public:
    explicit game_thread(QObject *parent = nullptr);

signals:

};
