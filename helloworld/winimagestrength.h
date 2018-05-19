#ifndef WINIMAGESTRENGTH_H
#define WINIMAGESTRENGTH_H

#include <QWidget>

#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "stdqtcvfile.h"
#include "stdimagebasic.h"

using namespace cv;
using namespace std;

namespace Ui {
class WinImageStrength;
}

class WinImageStrength : public QWidget
{
    Q_OBJECT

public:
    explicit WinImageStrength(QWidget *parent = 0);
    ~WinImageStrength();

private slots:
    void on_PbOpenFile_clicked();

    void on_PbbackToMain_clicked();

    void on_PbSaveFile_clicked();

    void on_PbAverage_clicked();

signals:
    void WinDisplay();

private:
    Ui::WinImageStrength *ui;
    QtCvFile QtCv;
    stdImageBasic ImageBasic;
    Mat matIn;
    QImage QImgIn;
    Mat matOut;
    QImage QImgOut;
};

#endif // WINIMAGESTRENGTH_H
