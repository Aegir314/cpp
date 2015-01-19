#include "bullet.h"
#include <QList>
#include <QTimer>
#include <typeinfo>


extern Game *game;

Bullet::Bullet(){

    setPixmap(QPixmap(":/images/bullet.png"));
    setTransformOriginPoint(this->pixmap().height()/2,this->pixmap().width()/2);
    setRotation(180);

    QTimer *timer = new QTimer();

    connect (timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for (int i=0; i< colliding_items.size();i++){
        if (typeid(*(colliding_items[i]))==typeid(Enemy)){
            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);
    if (pos().y()+10 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
