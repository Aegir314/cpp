#ifndef LINKFILTER_H
#define LINKFILTER_H

#include <QObject>
#include <QtCore>
#include <QtGui>

class linkFilter : public QObject
{
    Q_OBJECT
public:
    explicit linkFilter(QObject *parent = 0);

signals:
    void linkClicked (const QString&);
protected:
    bool eventFilter (QObject *, QEvent *);
public slots:

};

#endif // LINKFILTER_H
