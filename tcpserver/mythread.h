#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QThread
{
public:
    MyThread();
    ~MyThread();
};

#endif // MYTHREAD_H
