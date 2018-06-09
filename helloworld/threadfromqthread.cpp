#include "threadfromqthread.h"
#include <iostream>

using namespace std;

ThreadFromQthread::ThreadFromQthread(QObject *parent) : QThread(parent)
{
    RunCount = 0;
}

void ThreadFromQthread::StopImmediately()
{
    QMutexLocker locker(&islock);
    isCanRun = false;
}

ThreadFromQthread::~ThreadFromQthread()
{
    qDebug()<< "release this QTread";
}

void ThreadFromQthread::QThreadSendMesseage()
{
    msleep(500);
    QString str = QString("%1,thread id").arg(__FUNCTION__);
    //emit message(str);
}

void ThreadFromQthread::QThreadGetMesseage()
{
    msleep(500);
    //emit message(QString("%1,thread").arg(__FUNCTION__));
}

void ThreadFromQthread::SetRunCount(int count)
{
    RunCount = count;
    //emit message(QString("%1,thread").arg(__FUNCTION__));
}

void ThreadFromQthread::StartProgess(int i)
{
    msleep(500);
    //emit message(QString("%1,thread").arg(__FUNCTION__));
    cout << i<< endl;
}

void ThreadFromQthread::run()
{
    int count = 0;
    isCanRun = true; /*can be run*/
    QString str = QString("%1,thread id: %2").arg(__FUNCTION__);
    cout << "test"<< endl;
    while(1)
    {
        sleep(1);
        ++count;
        emit message(count);
        //emit progess((float)count/RunCount*100);
        StartProgess(count);
        if(RunCount == count)
        {
            break;
        }
        //QMutexLocker locker(&islock);
        if(!isCanRun)
        {
            return;
        }
    }
}


