#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QGraphicsTextItem>
#include "score.h"
#include "health.h"

class Game : public QGraphicsTextItem
{
public:
    Game();
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;

signals:

public slots:

};

#endif // GAME_H
