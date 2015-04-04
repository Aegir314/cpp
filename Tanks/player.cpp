#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
Player::Player(){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/fire.mp3"));

    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x()>0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x()+100<800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        scene()->addItem(bullet);
        bullet->setPos(x(),y());

        if (bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState){
        bulletSound->play();
        }

    }

}

void Player::spawn(){
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
