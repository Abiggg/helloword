#ifndef WINAIPHOTO_H
#define WINAIPHOTO_H

#include <QWidget>
#include <iostream>
#include <QString>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "stdqtcvfile.h"
#include "stdimagebasic.h"
#include "threadfromqthread.h"
#include "bpnetwork.h"

namespace Ui {
class winAiPhoto;
}

class winAiPhoto : public QWidget
{
    Q_OBJECT

public:
    explicit winAiPhoto(QWidget *parent = 0);
    ~winAiPhoto();

public:
    Mat matIn;
    QImage QImgIn;
    bool PhotoFlag;

public:
    void WinProgressBarInit(); /*Progress Bar Finish Percent*/
    void AiThreadInit();
    void StackWidgetInit();
    void LableEditInit();
    void BpLableEditInit();
    void LNetLableEditInit();
    void winAiPhotoInit();

signals:
    void WinDisplay();
    void WinBeatifyDisplay(Mat matCur);

private slots:
    void gotoAiPhoto_clicked_reshow(Mat SrcMat);

    void ReceiveMessage(int count);

    void ReceiveBpNetCrossEntroy(float CrossEntropy);

    void ReceiveBpTestResult(int BpImageNum, int BpTestValue, bool BpTestIsTrue);

    void on_PbBackToMain_clicked();

    void on_PbWinBeatify_clicked();

    void on_PbOpenFile_clicked();

    void on_PbSaveFile_clicked();

    void on_LwAiFun_currentRowChanged(int currentRow);

    void on_PbFlash_clicked();

    void on_PbBpStartTrain_clicked();

    void on_PbBpEndTrain_clicked();

    void on_PbBpStartTest_clicked();

    void on_PbBpEndTest_clicked();

    void on_PbLNetFlash_clicked();

private:
    Ui::winAiPhoto *ui;
    ThreadFromQthread *AiThread;
    //BpNetwork bpNetwork;

    QtCvFile QtCv;
    stdImageBasic ImageBasic;
    QImage QImgOut;
    Mat matCur;

};

#endif // WINAIPHOTO_H
