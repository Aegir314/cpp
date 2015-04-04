#include "enemy.h"
#include <QTimer>
#include <stdlib.h>

extern Game *game;

Enemy::Enemy(){
    int random_number = rand() %700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/enemy.png"));

    QTimer *timer = new QTimer();

    connect (timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if (pos().y() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
