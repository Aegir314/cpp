#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
private:
    QMediaPlayer *bulletSound;
public slots:
    void spawn();
};

#endif // MYRECT_H
