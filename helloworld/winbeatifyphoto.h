#ifndef WINBEATIFYPHOTO_H
#define WINBEATIFYPHOTO_H

#include <QWidget>
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "stdqtcvfile.h"
#include "stdimagebasic.h"

namespace Ui {
class WinBeatifyPhoto;
}

class WinBeatifyPhoto : public QWidget
{
    Q_OBJECT

public:
    Mat matIn;
    QImage QImgIn;
    bool PhotoFlag;

    void SpinBoxInit();
    void VectorSliderInit();
    void WinInit();

public:
    explicit WinBeatifyPhoto(QWidget *parent = 0);
    ~WinBeatifyPhoto();

signals:
    void WinDisplay();

private slots:
    void on_PbBackToMain_clicked();

    void on_PbLast_clicked();

    void on_PbConfirm_clicked();

    void on_PbOpenFile_clicked();

    void on_PbSaveFile_clicked();

    void on_PbBiarization_clicked();

    void on_PbEquration_clicked();

    void on_PbGrayScale_clicked();

    void on_PbYMinior_clicked();

    void on_PbXMinior_clicked();

    void on_PbFuzzy_clicked();

    void on_PbGaussian_clicked();

    void on_VsBrightness_sliderMoved(int position);

    void on_VsConstration_sliderMoved(int position);

    void on_VsSaturation_sliderMoved(int position);

    void on_PbClassical_clicked();

    void on_PbSketch_clicked();

    void on_PbResetAll_clicked();

    void on_PbOilPaint_clicked();

    void on_PbLaplaceShape_clicked();



    void on_PbShapen_clicked();

    void on_PbCorrosion_clicked();

    void on_PbExpand_clicked();

private:
    Ui::WinBeatifyPhoto *ui;
    QtCvFile QtCv;
    stdImageBasic ImageBasic;

    QImage QImgOut;
    Mat matPre[10];
    uint32 matPreKey;
    Mat matCur;
    Mat matNext[10];
    uint32 matNextKey;

};

#endif // WINBEATIFYPHOTO_H
