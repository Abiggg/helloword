#include "winimagefuzzy.h"
#include "ui_winimagefuzzy.h"

#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

WinImageFuzzy::WinImageFuzzy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinImageFuzzy)
{
    ui->setupUi(this);
}

WinImageFuzzy::~WinImageFuzzy()
{
    delete ui;
}

void WinImageFuzzy::on_PbOpenFile_clicked()
{
    Mat src1 = imread("/home/abig/dog.jpg" );//读入一站图片 暂时读入桌面上的一个文件
    cvtColor(src1,src1,CV_BGR2RGB);//opencv读取图片按照BGR方式读取，为了正常显示，所以将BGR转为RGB
    QImage showImage((const uchar*)src1.data,src1.cols,src1.rows,src1.cols*src1.channels(),QImage::Format_RGB888);

    ui->LbInputImage->setPixmap(QPixmap::fromImage(showImage));
}

void WinImageFuzzy::on_PbbackToMain_clicked()
{
    emit WinDisplay();
    this->close();
}
