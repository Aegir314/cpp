#include "health.h"
#include <QFont>

Health::Health(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
    health = 3;
    setPlainText((QString)"Health: "+ QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("sans",16));
}

void Health::decrease(){
    health--;
    setPlainText((QString)"Health: "+ QString::number(health));

}

int Health::getHealth(){
    return health;
}
