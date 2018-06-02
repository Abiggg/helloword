#include "winaiphoto.h"
#include "ui_winaiphoto.h"
#include "winbeatifyphoto.h"
#include "mainwindow.h"
using namespace cv;
using namespace std;

winAiPhoto::winAiPhoto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winAiPhoto)
{
    ui->setupUi(this);
}

winAiPhoto::~winAiPhoto()
{
    delete ui;
}

/*init*/
void winAiPhoto::winAiPhotoInit()
{
    /*Init Class variable*/

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

/*reshow this window*/
void winAiPhoto::on_gotoAiPhoto_clicked_reshow(Mat SrcMat)
{
    matIn = SrcMat;
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matIn, QImgIn));
    CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
    this->show();
}

/*Back to main*/
void winAiPhoto::on_PbBackToMain_clicked()
{
    emit WinDisplay();
    this->close();
}

/*got to Win BeatifyPhoto*/
void winAiPhoto::on_PbWinBeatify_clicked()
{
    emit WinBeatifyDisplay(matCur);
    this->close();
}

/*Open file*/
void winAiPhoto::on_PbOpenFile_clicked()
{
    CHECK(QtCv.OpenImageFile(matIn));   //open image file
    CHECK(QtCv.cvMat2QImage(matIn,QImgIn));     //convert image file
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn)); //show image in inputLable
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
}

/*save file*/
void winAiPhoto::on_PbSaveFile_clicked()
{
    CHECK(QtCv.SaveImageFile(matCur)); //save image
    ui->TbHint->setText(QString::fromStdString("save image \
    , please choose this storage root and putting the image name"));
}
