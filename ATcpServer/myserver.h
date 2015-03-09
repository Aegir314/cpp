#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "myclient.h"

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit MyServer(QObject *parent=0);
    void StartServer();

protected:
    void incomingConnection(qintptr handle);
signals:

public slots:


};


#endif // MYSERVER_H
