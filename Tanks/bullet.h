#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include "enemy.h"
#include "game.h"

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();

signals:

public slots:
    void move();
};

#endif // BULLET_H
