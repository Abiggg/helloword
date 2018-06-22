#include "threadfromqthread.h"
#include <iostream>

using namespace std;

ThreadFromQthread::ThreadFromQthread(QObject *parent) : QThread(parent)
{
    RunCount = 0;
    isPhoto = false;
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

void ThreadFromQthread::keyPressEvent(QKeyEvent *k)
{
    if(k->key())
    {
        isPhoto = ~isPhoto;
    }
}

void ThreadFromQthread::StartProgess(int i)
{
    msleep(500);
    cout << i<< endl;
}

void ThreadFromQthread::run()
{
    int count = 0;
    isCanRun = true; /*can be run*/
    while(1)
    {
        sleep(1);
        ++count;
        emit message(count);
        //QKeyEventDetect();
        bpNetwork.BpNetWorkTrain();
        emit sendCrossEntropy(bpNetwork.CrossEntropy);

        if(RunCount == count)
        {
            break;
        }
        if(!isCanRun)
        {
            return;
        }
    }
}


