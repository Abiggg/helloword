#include "winaiphoto.h"
#include "ui_winaiphoto.h"
#include "winbeatifyphoto.h"
#include "mainwindow.h"
#include "threadfromqthread.h"
#include "mathlib.h"

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

/*Finish Percent*/
void winAiPhoto::WinProgressBarInit()
{
    ui->PgFinishPercent->setRange(0,100);
    ui->PgFinishPercent->setValue(0);
}

/*Ai Thread Init*/
void winAiPhoto::AiThreadInit()
{
    AiThread = new ThreadFromQthread();
    connect(this->AiThread, SIGNAL(message(int)), this, SLOT(ReceiveMessage(int)));//当点击子界面时，调用主界面的reshow()函数
}

void winAiPhoto::StackWidgetInit()
{
    ui->SwAiFun->setCurrentIndex(0);
}

/*StackWidget Init*/


/*init*/
void winAiPhoto::winAiPhotoInit()
{
    /*Init Class variable*/
    WinProgressBarInit();

    /*Init Thread*/
    AiThreadInit();

    /*Init StackWidget Init*/
    StackWidgetInit();

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
void winAiPhoto::gotoAiPhoto_clicked_reshow(Mat SrcMat)
{
    matIn = SrcMat;
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matIn, QImgIn));
    CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
    this->show();

    /*Init other things*/
    WinProgressBarInit();

    /*Init Thread*/
    AiThreadInit();

    /*Init StackWidget Init*/
    StackWidgetInit();

}

void winAiPhoto::ReceiveMessage(int count)
{
    ui->PgFinishPercent->setValue(count);
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

/*Start Train*/
void winAiPhoto::on_PbStratTrain_clicked()
{
    if(AiThread->isRunning())
    {
        return;
    }
     AiThread->start(); /*Start a thread*/
}

/*Stop Train*/
void winAiPhoto::on_PbEndTrain_clicked()
{
    AiThread->terminate();  /*end this thread*/
}

/*ListWiget Change*/
void winAiPhoto::on_LwAiFun_currentRowChanged(int currentRow)
{
    switch (currentRow)
    {
        case 0:
            ui->SwAiFun->setCurrentIndex(0);
            break;
        case 1:
            ui->SwAiFun->setCurrentIndex(1);
            break;
        case 2:
            ui->SwAiFun->setCurrentIndex(2);
            break;
        case 3:
            ui->SwAiFun->setCurrentIndex(3);
            break;
        case 4:
            ui->SwAiFun->setCurrentIndex(4);
            break;
        case 5:
            ui->SwAiFun->setCurrentIndex(5);
            break;
        case 6:
            ui->SwAiFun->setCurrentIndex(6);
            break;
        case 7:
            ui->SwAiFun->setCurrentIndex(7);
            break;
        default:
            break;
    }
}



/*Start Bp train*/
void winAiPhoto::on_PbBpStart_clicked()
{
    GetRamdom_B1_1();
}
