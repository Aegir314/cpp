#include "mytask.h"

MyTask::MyTask()
{

}

MyTask::~MyTask()
{

}

void MyTask::run()
{
    qDebug()<<"Tast Started";

    int iNumber= 0;
    for (int i=0; i<100;i++){
        iNumber+=i;
    }
    qDebug()<<"Task Done";
    emit(Result(iNumber));
}

