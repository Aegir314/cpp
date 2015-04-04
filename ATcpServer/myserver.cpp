#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer (parent)
{

}

void MyServer::StartServer()
{
    if (listen(QHostAddress::Any,1234)){
        qDebug() << "Starded";

    } else {
        qDebug()<<"Failed to start";
    }
}

void MyServer::incomingConnection(qintptr handle)
{
    MyClient *client = new MyClient(this);
    client->SetSocket(handle);
}
