#ifndef WINIMAGEFUZZY_H
#define WINIMAGEFUZZY_H

#include <QWidget>

#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "stdqtcvfile.h"
#include "stdimagebasic.h"
#include <qpixmapcache.h>

using namespace cv;
using namespace std;

namespace Ui {
class WinImageFuzzy;
}

class WinImageFuzzy : public QWidget
{
    Q_OBJECT

public:
    explicit WinImageFuzzy(QWidget *parent = 0);
    ~WinImageFuzzy();
public:
    uint8 FilterSize;

private slots:
    void on_PbOpenFile_clicked();

    void on_PbbackToMain_clicked();

    void on_PbSaveFile_clicked();

    void on_PbAverage_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_PbClear_clicked();


    void on_PbGaussian_clicked();

signals:
    void WinDisplay();

private:
    Ui::WinImageFuzzy *ui;
    QtCvFile QtCv;
    stdImageBasic ImageBasic;
    Mat matIn;
    QImage QImgIn;
    Mat matOut;
   QImage QImgOut;

    /*globle variable */

};

#endif // WINIMAGEFUZZY_H
