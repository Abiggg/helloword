#ifndef THREADFROMQTHREAD_H
#define THREADFROMQTHREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <iostream>
#include <QtCore/QtCore>

class ThreadFromQthread : public QThread
{
    Q_OBJECT
signals:
    void message(int count);
    void progess(int present);

public slots:
    void StopImmediately();
public:
    ThreadFromQthread(QObject * parent = 0);
    ~ThreadFromQthread();

    void QThreadSendMesseage();
    void QThreadGetMesseage();
    void SetRunCount(int count);
    void StartProgess(int i);
    void run();

private:
    int RunCount;
    QMutex islock;
    bool isCanRun;
};

#endif // THREADFROMQTHREAD_H
