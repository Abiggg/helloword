#ifndef WINAIPHOTO_H
#define WINAIPHOTO_H

#include <QWidget>
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "stdqtcvfile.h"
#include "stdimagebasic.h"

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
    void winAiPhotoInit();

signals:
    void WinDisplay();
    void WinBeatifyDisplay(Mat matCur);

private slots:
    void on_gotoAiPhoto_clicked_reshow(Mat SrcMat);

    void on_PbBackToMain_clicked();

    void on_PbWinBeatify_clicked();

    void on_PbOpenFile_clicked();

    void on_PbSaveFile_clicked();

private:
    Ui::winAiPhoto *ui;

    QtCvFile QtCv;
    stdImageBasic ImageBasic;
    QImage QImgOut;
    Mat matCur;
};

#endif // WINAIPHOTO_H
