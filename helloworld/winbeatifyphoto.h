#ifndef WINBEATIFYPHOTO_H
#define WINBEATIFYPHOTO_H

#include <QWidget>
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "datast.h"
#include "stdqtcvfile.h"
#include "stdimagebasic.h"

#define MaxTempSaveNum 10

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

    /*Init SpinBox*/
    void SpinBoxInit();
    /*Init Vector*/
    void VectorSliderInit();
    /*Init Win*/
    void WinInit();
    /*Init TempSavemat*/
    void TempSavematInit();

public:
    explicit WinBeatifyPhoto(QWidget *parent = 0);
    ~WinBeatifyPhoto();

signals:
    /*emit signal to back to mainwind*/
    void WinDisplay();
    /*emit signal to go to winAi*/
    void WinAiDisplay(Mat matCur);

private slots:
    void gotoBeatifyPhoto_clicked_reshow(Mat matSrc);

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

    void on_PbWinAiPhoto_clicked();

    void on_PbNext_clicked();

    void on_PbRatation_clicked();

    void on_PbFFtBandFilter_clicked();

    void on_PbFFtLowFilter_clicked();

    void on_PbFFtHighFilter_clicked();

private:
    Ui::WinBeatifyPhoto *ui;
    QtCvFile QtCv;
    stdImageBasic ImageBasic;

    QImage QImgOut;/*current Qimg show in right*/
    Mat matCur; /*current mat show in right*/

    pDoubleLq_S TempSavemat_last; /*last mat show in right stroge*/
    pDoubleLq_S TempSavemat_next; /*next mat show in next stroge*/
    int TempSavemat_pos_last;  /*last mat position*/
    int TempSavemat_pos_next;  /*next mat position*/
};

#endif // WINBEATIFYPHOTO_H
