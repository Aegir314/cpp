#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>

class MyServer : public QTcpServer
{
public:
    MyServer();
    ~MyServer();
};

#endif // MYSERVER_H
