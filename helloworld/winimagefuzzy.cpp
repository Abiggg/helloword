#include "winimagefuzzy.h"
#include "ui_winimagefuzzy.h"

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

void WinImageFuzzy::on_PbbackToMain_clicked()
{
    emit WinDisplay();
    this->close();
}

void WinImageFuzzy::on_PbOpenFile_clicked()
{
    CHECK(QtCv.OpenImageFile(matIn));   //open image file
    CHECK(QtCv.cvMat2QImage(matIn,QImgIn));     //convert image file
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn)); //show image in inputLable
}

void WinImageFuzzy::on_PbSaveFile_clicked()
{
    CHECK(QtCv.QImage2cvMat(QImgOut, matOut)); //change qimg to img
    CHECK(QtCv.SaveImageFile(matOut)); //save image
}

void WinImageFuzzy::on_PbAverage_clicked()
{
    QImage *qimg;
    qimg = new QImage((unsigned char*)matIn.data, // uchar* data
            matIn.cols, matIn.rows, // width height
            matIn.step, //bytesPerLine
            QImage::Format_RGB888); //format
    CHECK(ImageBasic.ImageFuzzyAverage(matIn, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(*qimg));
    delete qimg;
    qimg = NULL;
}

void WinImageFuzzy::on_horizontalSlider_sliderMoved(int position)
{
    FilterSize = position*2+1;
    if(FilterSize > 99)
    {
        FilterSize = 99;
    }
    QString n = QString::number(FilterSize,10);
    ui->LbFiterSizeValue->setText(n);
}

void WinImageFuzzy::on_PbClear_clicked()
{
     ui->LbOutputImage->clear();
     QPixmapCache::clear();
}



void WinImageFuzzy::on_PbGaussian_clicked()
{
    QImage *qimg;
    qimg = new QImage((unsigned char*)matIn.data, // uchar* data
            matIn.cols, matIn.rows, // width height
            matIn.step, //bytesPerLine
            QImage::Format_RGB888); //format

    CHECK(ImageBasic.ImageGaussian(matIn,qimg,FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(*qimg));
    delete qimg;
    qimg = NULL;
}
