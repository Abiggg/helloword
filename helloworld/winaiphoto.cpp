#include "winaiphoto.h"
#include "ui_winaiphoto.h"
#include "winbeatifyphoto.h"
#include "mainwindow.h"
#include "threadfromqthread.h"
#include "mathlib.h"
#include "stdfile.h"

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
    connect(this->AiThread, SIGNAL(sendCrossEntropy(float)), this, SLOT(ReceiveBpNetCrossEntroy(float)));//当点击子界面时，调用主界面的reshow()函数
}

void winAiPhoto::StackWidgetInit()
{
    ui->SwAiFun->setCurrentIndex(0);
}

void winAiPhoto::LableEditInit()
{
    /*BpLableEditInit*/
    BpLableEditInit();
}

void winAiPhoto::BpLableEditInit()
{
    ui->LeImageRoot->setText("/home/abig/project/project4/train_image/");
    ui->LeLableRoot->setText("/home/abig/project/project4/train_lable/train_lable.txt");
    ui->LeSaveRoot->setText("/home/abig/project/project4/train_lable/data.txt");
    ui->LeInNum->setText("784");
    ui->LeHdNum->setText("700");
    ui->LeOutNum->setText("10");

    ui->LeLearnRate->setText("0.5");
    ui->LeBatchSize->setText("100");
    ui->LeTrainNum->setText("60000");
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

    /*LableEditInit*/
    LableEditInit();

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
        matIn = imread("/home/abig/project/project4/train_image/0.png");
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

    /*LableEditInit*/
    LableEditInit();

}

void winAiPhoto::ReceiveMessage(int count)
{

    ui->PgFinishPercent->setValue(count);
}

void winAiPhoto::ReceiveBpNetCrossEntroy(float CrossEntropy)
{
    string strHint = "the cross Entropy is :" + to_string(CrossEntropy);
    ui->TbHint->setText(QString::fromStdString(strHint));
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

/*Flash Bp*/
void winAiPhoto::on_PbFlash_clicked()
{
    QString QsLableRoot = ui->LeLableRoot->text();
    QString QsImageRoot = ui->LeImageRoot->text();
    QString QsSaveRoot = ui->LeSaveRoot->text();
    QString QsInNum = ui->LeInNum->text();
    QString QsHdNum = ui->LeHdNum->text();
    QString QsOutNum = ui->LeOutNum->text();
    QString QsLearnRate = ui->LeLearnRate->text();
    QString QsBatchSize = ui->LeBatchSize->text();
    QString QsTrainNum = ui->LeTrainNum->text();

    string sLableRoot = QsLableRoot.toStdString();
    string sImageRoot = QsImageRoot.toStdString();
    string sSaveRoot = QsSaveRoot.toStdString();
    string sInNum = QsInNum.toStdString();
    string sHdNum = QsHdNum.toStdString();
    string sOutNum = QsOutNum.toStdString();
    string sLearnRateNum = QsLearnRate.toStdString();
    string sBatchSizeNum = QsBatchSize.toStdString();
    string sTrainNum = QsTrainNum.toStdString();

    AiThread->bpNetwork.sLableRoot = sLableRoot;
    AiThread->bpNetwork.sImageRoot = sImageRoot;
    AiThread->bpNetwork.sSaveRoot = sSaveRoot;
    AiThread->bpNetwork.inNum = atoi(sInNum.c_str());
    AiThread->bpNetwork.inNum = atoi(sInNum.c_str());
    AiThread->bpNetwork.inNum = atoi(sInNum.c_str());
    AiThread->bpNetwork.hdNum = atoi(sHdNum.c_str());
    AiThread->bpNetwork.OutNum = atoi(sOutNum.c_str());
    AiThread->bpNetwork.BatchSize = atoi(sBatchSizeNum.c_str());
    AiThread->bpNetwork.TrainNum = atoi(sTrainNum.c_str());
    AiThread->bpNetwork.LearingRate = atof(sLearnRateNum.c_str());

    AiThread->bpNetwork.BpNetWortInit();
}

/*Start Bp Train*/
void winAiPhoto::on_PbBpStartTrain_clicked()
{
    if(AiThread->isRunning())
    {
        return;
    }
     AiThread->start(); /*Start a thread*/
}

/*End Bp Train*/
void winAiPhoto::on_PbBpEndTrain_clicked()
{
    AiThread->terminate();  /*end this thread*/
}
