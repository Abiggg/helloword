#ifndef THREADFROMQTHREAD_H
#define THREADFROMQTHREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <iostream>
#include <QtCore/QtCore>
#include <QKeyEvent>

#include "bpnetwork.h"
#include "lenet.h"

class ThreadFromQthread : public QThread
{
    Q_OBJECT

signals:
    void message(int count);
    void progess(int present);
    void sendCameraStatus(bool isPhoto);
    void sendCrossEntropy(float CrossEntropy);
    void sendBpTestResult(int BpImageNum, int value, bool isTrue);

public slots:
    void StopImmediately();

public:
    ThreadFromQthread(QObject * parent = 0);
    ~ThreadFromQthread();

    void keyPressEvent(QKeyEvent *k);
    void SetRunCount(int count);
    void StartProgess(int i);
    void run();

public:
    int branch;
    bool isPhoto;
    BpNetwork bpNetwork;
    LeNet leNet;

private:
    int RunCount;
    QMutex islock;
    bool isCanRun;
};

#endif // THREADFROMQTHREAD_H
