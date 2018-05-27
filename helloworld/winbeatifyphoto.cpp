#include "winbeatifyphoto.h"
#include "ui_winbeatifyphoto.h"
#include <QString>

using namespace cv;
using namespace std;

WinBeatifyPhoto::WinBeatifyPhoto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinBeatifyPhoto)
{
    ui->setupUi(this);
}

WinBeatifyPhoto::~WinBeatifyPhoto()
{
    delete ui;
}

/*SpinBox Init*/
void WinBeatifyPhoto::SpinBoxInit()
{
    ui->SbCorrosion->setRange(3,255);
    ui->SbCorrosion->setSingleStep(2);

    ui->SbExpand->setRange(3,255);
    ui->SbExpand->setSingleStep(2);

    ui->SbFuzzy->setRange(1,99);
    ui->SbFuzzy->setSingleStep(2);

    ui->SbFilter->setRange(1,99);
    ui->SbFilter->setSingleStep(2);

    ui->SbSharpen->setRange(1,99);
    ui->SbSharpen->setSingleStep(2);

    ui->SbRatation->setRange(0,10000);
    ui->SbRatation->setSingleStep(1);

    ui->SbGaussian->setRange(1,99);
    ui->SbGaussian->setSingleStep(2);

    ui->SbSketch->setRange(1,255);
    ui->SbSketch->setSingleStep(1);

    ui->SbOilPaint->setRange(3,255);
    ui->SbOilPaint->setSingleStep(2);
}

/*Vector Slider init*/
void WinBeatifyPhoto::VectorSliderInit()
{
    ui->VsBrightness->setRange(0,200);
    ui->VsBrightness->setSliderPosition(100);

    ui->VsConstration->setRange(0,200);
    ui->VsConstration->setSliderPosition(100);

    ui->VsSaturation->setRange(0,200);
    ui->VsSaturation->setSliderPosition(100);
}

/*Win init*/
void WinBeatifyPhoto::WinInit()
{
    /*Init Class variable*/
    matPreKey = 0;

    /*init SpinBox*/
    SpinBoxInit();

    /*Slider Init*/
    VectorSliderInit();

    /*init Input and Output Box*/
    if(PhotoFlag)
    {
         matCur = matIn.clone();
         CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
         ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn));
         ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
         PhotoFlag = false;
    }
    else
    {
        matIn = imread("/home/abig/bitch.png");
        matCur = matIn.clone();
        CHECK(QtCv.cvMat2QImage(matCur, QImgIn));
        CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
        ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn));
        ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
    }
}

/*Open Image*/
void WinBeatifyPhoto::on_PbOpenFile_clicked()
{
    CHECK(QtCv.OpenImageFile(matIn));   //open image file
    CHECK(QtCv.cvMat2QImage(matIn,QImgIn));     //convert image file
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn)); //show image in inputLable
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
}

/*PushBotton Back to Main*/
void WinBeatifyPhoto::on_PbBackToMain_clicked()
{
    emit WinDisplay();
    this->close();
}

/*PushBotton Last*/
void WinBeatifyPhoto::on_PbLast_clicked()
{
    if(matPreKey > 0)
    {
        matCur = matPre[matPreKey].clone();
        matPreKey -= 1;
    }
}

/*Confirm This Step*/
void WinBeatifyPhoto::on_PbConfirm_clicked()
{
    matCur = ImageBasic.matOut;
    if(matPreKey<10)
    {
        matPre[matPreKey] = matCur.clone();
        ui->TbHint->setText(QString::fromStdString("save this step success!"));
    }
    else
    {}

}

/*Reset in Oringal Picture*/
void WinBeatifyPhoto::on_PbResetAll_clicked()
{
    QImage qimg;
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matCur, qimg));
     ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Save Picture*/
void WinBeatifyPhoto::on_PbSaveFile_clicked()
{
    CHECK(QtCv.SaveImageFile(matCur)); //save image
    ui->TbHint->setText(QString::fromStdString("save image \
    , please choose this storage root and putting the image name"));
}

/*Biarization*/
void WinBeatifyPhoto::on_PbBiarization_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageBinary(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Equration*/
void WinBeatifyPhoto::on_PbEquration_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageEquration(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*GrayScale*/
void WinBeatifyPhoto::on_PbGrayScale_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageGrayscal(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Minior Y*/
void WinBeatifyPhoto::on_PbYMinior_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageYminor(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Minor X*/
void WinBeatifyPhoto::on_PbXMinior_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageXminor(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Fuzzy*/
void WinBeatifyPhoto::on_PbFuzzy_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbFuzzy->value();
    CHECK(ImageBasic.ImageFuzzyAverage(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Gaussian Fuzzy*/
void WinBeatifyPhoto::on_PbGaussian_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbGaussian->value();

    CHECK(ImageBasic.ImageGaussian(matCur,qimg,FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Bright*/
void WinBeatifyPhoto::on_VsBrightness_sliderMoved(int position)
{
    QImage qimg;
    uint8 ratioBrightness = position;
    CHECK(ImageBasic.ImageBrightness(matCur, qimg, ratioBrightness));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Constrat*/
void WinBeatifyPhoto::on_VsConstration_sliderMoved(int position)
{
    QImage qimg;
    uint8 ratioConstrast = position;
    CHECK(ImageBasic.ImageConstrast(matCur, qimg, ratioConstrast));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Saturation*/
void WinBeatifyPhoto::on_VsSaturation_sliderMoved(int position)
{
    QImage qimg;
    uint8 ratioSaturation = position;
    CHECK(ImageBasic.ImageSaturation(matCur, qimg, ratioSaturation));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Classical Style*/
void WinBeatifyPhoto::on_PbClassical_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageClassical(matCur, qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Sketch style*/
void WinBeatifyPhoto::on_PbSketch_clicked()
{
    QImage qimg;
    uint8 SketchThrehold = (uint8) ui->SbSketch->value();

    CHECK(ImageBasic.ImageSketch(matCur,qimg,SketchThrehold));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*OilPaint style*/
void WinBeatifyPhoto::on_PbOilPaint_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbOilPaint->value();

    CHECK(ImageBasic.ImageOilPaint(matCur,qimg,FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Laplace Shapen*/
void WinBeatifyPhoto::on_PbLaplaceShape_clicked()
{
    QImage qimg;
    uint8 FilterSize = 3;
    CHECK(ImageBasic.ImageScalar(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

void WinBeatifyPhoto::on_PbShapen_clicked()
{
    QImage qimg;
    uint8 RatioShape = (uint8) ui->SbSharpen->value();
    CHECK(ImageBasic.ImageShapen(matCur, qimg, RatioShape));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

void WinBeatifyPhoto::on_PbCorrosion_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbCorrosion->value();
    CHECK(ImageBasic.ImageCorrosion(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

void WinBeatifyPhoto::on_PbExpand_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbExpand->value();
    CHECK(ImageBasic.ImageExpand(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}
