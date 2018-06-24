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
    int TestNum = 0;
    isCanRun = true; /*can be run*/

    Mat BpTestMatOut;
    int BpTestValue = 0;
    bool BpTestIsTrue = false;

    while(1)
    {
        sleep(1);
        switch(branch)
        {
            case 0:/*test*/
                ++count;
                emit message(count);
                continue;

            case 1: /*bpTrain*/
                bpNetwork.BpNetWorkTrain();
                emit sendCrossEntropy(bpNetwork.CrossEntropy);
                continue;

            case 2: /*BpTest*/
                bpNetwork.BpNetWorkTest(TestNum, BpTestMatOut, BpTestValue, BpTestIsTrue);
                emit sendBpTestResult(TestNum, BpTestValue, BpTestIsTrue);
                TestNum ++;
                continue;

            case 3:
                //QKeyEventDetect();
            default:
                cout<<"error"<<endl;
        }
    }
}


