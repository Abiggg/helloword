#include "winimagestrength.h"
#include "ui_winimagestrength.h"

#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include "stdqtcvfile.h"

using namespace cv;
using namespace std;


WinImageStrength::WinImageStrength(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinImageStrength)
{
    ui->setupUi(this);
}

WinImageStrength::~WinImageStrength()
{
    delete ui;
}

void WinImageStrength::on_PbOpenFile_clicked()
{

    QtCvFile OpenFile;
    Mat image;
    QImage QImg;
    CHECK(OpenFile.OpenImageFile(&image));   //open image file
    CHECK(OpenFile.cvMat2QImage(image,QImg));     //convert image file
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImg));
}

void WinImageStrength::on_PbbackToMain_clicked()
{
    emit WinDisplay();
    this->close();
}

void WinImageStrength::on_PbSaveFile_clicked()
{

}

void WinImageStrength::on_PbAverage_clicked()
{
    QImage Qimg;
    Qimg = ui->LbInputImage->pixmap()->toImage();
    /*Strength Algorithm*/
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(Qimg));
}
