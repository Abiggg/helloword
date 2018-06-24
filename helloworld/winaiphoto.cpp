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
    AiThread->branch =1;
    connect(this->AiThread, SIGNAL(message(int)), this, SLOT(ReceiveMessage(int)));//当点击子界面时，调用主界面的reshow()函数
    connect(this->AiThread, SIGNAL(sendCrossEntropy(float)), this, SLOT(ReceiveBpNetCrossEntroy(float)));//当点击子界面时，调用主界面的reshow()函数
    connect(this->AiThread, SIGNAL(sendBpTestResult(int, int, bool)), this, SLOT(ReceiveBpTestResult(int, int, bool)));//当点击子界面时，调用主界面的reshow()函数
}

void winAiPhoto::StackWidgetInit()
{
    ui->SwAiFun->setCurrentIndex(0);
}

void winAiPhoto::LableEditInit()
{
    /*BpLableEditInit*/
    BpLableEditInit();
    LNetLableEditInit();
}

void winAiPhoto::BpLableEditInit()
{
    ui->LeImageRoot->setText("/home/abig/project/project4/train_image/");
    ui->LeLableRoot->setText("/home/abig/project/project4/train_lable/train_lable.txt");
    ui->LeSaveRoot->setText("/home/abig/project/project4/train_lable/data.txt");
    ui->LeInNum->setText("784");
    ui->LeHdNum->setText("500");
    ui->LeOutNum->setText("10");

    ui->LeLearnRate->setText("1");
    ui->LeBatchSize->setText("100");
    ui->LeTrainNum->setText("60000");
}

void winAiPhoto::LNetLableEditInit()
{
    ui->LeLNetImgRoot->setText("/home/abig/project/project4/train_image/");
    ui->LeLNetLbRoot->setText("/home/abig/project/project4/train_lable/train_lable.txt");
    ui->LeLNetSaveRoot->setText("/home/abig/project/project4/train_lable/data.txt");

    ui->LeLNetBatchSize->setText("100");
    ui->LeLNetLearnRate->setText("0.8");
    ui->LeLNetTrainNum->setText("60000");

    ui->LeLNetCon1Chl->setText("6");
    ui->LeLNetCon1Size->setText("5");
    ui->LeLNetPool1Size->setText("2");

    ui->LeLNetCon2Chl->setText("16");
    ui->LeLNetCon2Size->setText("5");
    ui->LeLNetPool2Size->setText("2");

    ui->LeLNetFc2Num->setText("120");
    ui->LeLNetFc3Num->setText("84");
    ui->LeLNetImgSize->setText("32");

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

void winAiPhoto::ReceiveBpTestResult(int BpImageNum, int BpTestValue, bool BpTestIsTrue)
{
    QString QsImageRoot = ui->LeImageRoot->text();
    string sImageRoot = QsImageRoot.toStdString();
    sImageRoot = sImageRoot + to_string((int)BpImageNum) + ".png";
    Mat matRead = imread(sImageRoot);
    QImage qimg;
    CHECK(QtCv.cvMat2QImage(matRead,qimg));
    ui->LbInputImage->setPixmap(QPixmap::fromImage(qimg));

    string strHint;
    QFont font("Microsoft YaHei", 50, 75);
    string strVaule = to_string((int)BpTestValue);
    ui->LbOutputImage->setText(QString::fromStdString(strVaule));
    ui->LbOutputImage->setFont(font);

    if(BpTestIsTrue == true)
    {
         strHint = "Test Result is : True";
    }
    else
    {
         strHint = "Test Result is : false";
    }
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

/*Flash LeNet*/
void winAiPhoto::on_PbLNetFlash_clicked()
{
    QString QsLeLNetLbRoot = ui->LeLNetLbRoot->text();
    QString QsLeLNetImgRoot = ui->LeLNetImgRoot->text();
    QString QsLeLNetSaveRoot = ui->LeLNetSaveRoot->text();

    QString QsLeLNetImgSize = ui->LeLNetImgSize->text();
    QString QsLeLNetFc2Num = ui->LeLNetFc2Num->text();
    QString QsLeLNetFc3Num = ui->LeLNetFc3Num->text();

    QString QsLeLNetCon1Chl = ui->LeLNetCon1Chl->text();
    QString QsLeLNetCon1Size = ui->LeLNetCon1Size->text();
    QString QsLeLNetPool1Size = ui->LeLNetPool1Size->text();
    \
    QString QsLeLNetCon2Chl = ui->LeLNetCon2Chl->text();
    QString QsLeLNetCon2Size = ui->LeLNetCon2Size->text();
    QString QsLeLNetPool2Size = ui->LeLNetPool2Size->text();

    QString QsLeLNetLearnRate = ui->LeLNetLearnRate->text();
    QString QsLeLNetBatchSize = ui->LeLNetBatchSize->text();
    QString QsLeLNetTrainNum = ui->LeLNetTrainNum->text();

    string sLeLNetLbRoot = QsLeLNetLbRoot.toStdString();
    string sLeLNetImgRoot = QsLeLNetImgRoot.toStdString();
    string sLeLNetSaveRoot = QsLeLNetSaveRoot.toStdString();

    string sLeLNetImgSize = QsLeLNetImgSize.toStdString();
    string sLeLNetFc2Num = QsLeLNetFc2Num.toStdString();
    string sLeLNetFc3Num = QsLeLNetFc3Num.toStdString();

    string sLeLNetCon1Chl = QsLeLNetCon1Chl.toStdString();
    string sLeLNetCon1Size = QsLeLNetCon1Size.toStdString();
    string sLeLNetPool1Size = QsLeLNetPool1Size.toStdString();

    string sLeLNetCon2Chl = QsLeLNetCon2Chl.toStdString();
    string sLeLNetCon2Size = QsLeLNetCon2Size.toStdString();
    string sLeLNetPool2Size = QsLeLNetPool2Size.toStdString();

    string sLeLNetLearnRate = QsLeLNetLearnRate.toStdString();
    string sLeLNetBatchSize = QsLeLNetBatchSize.toStdString();
    string sLeLNetTrainNum = QsLeLNetTrainNum.toStdString();

    AiThread->leNet.sLNetLableRoot = sLeLNetLbRoot;
    AiThread->leNet.sLNetImageRoot = sLeLNetImgRoot;
    AiThread->leNet.sLNetSaveRoot = sLeLNetSaveRoot;

    AiThread->leNet.LNetImgSize = atoi(sLeLNetImgSize.c_str());
    AiThread->leNet.LNetFc2Num = atof(sLeLNetFc2Num.c_str());
    AiThread->leNet.LNetFc3Num = atof(sLeLNetFc3Num.c_str());

    AiThread->leNet.LNetCon1Size = atoi(sLeLNetCon1Size.c_str());
    AiThread->leNet.LNetCon1Chl = atoi(sLeLNetCon1Chl.c_str());
    AiThread->leNet.LNetPool1Size = atoi(sLeLNetPool1Size.c_str());

    AiThread->leNet.LNetCon2Size = atoi(sLeLNetCon2Size.c_str());
    AiThread->leNet.LNetCon2Chl = atoi(sLeLNetCon2Chl.c_str());
    AiThread->leNet.LNetPoo21Size = atoi(sLeLNetPool2Size.c_str());

    AiThread->leNet.LNetLearnRate = atof(sLeLNetLearnRate.c_str());
    AiThread->leNet.LNetBatchSize = atof(sLeLNetBatchSize.c_str());
    AiThread->leNet.LNetTrainNum = atof(sLeLNetTrainNum.c_str());

    AiThread->leNet.LeNetInit();
}


/*Start Bp Train*/
void winAiPhoto::on_PbBpStartTrain_clicked()
{
    AiThread->branch =1;
    if(AiThread->isRunning())
    {
        return;
    }
     AiThread->start(); /*Start a thread*/
}

/*End Bp Train*/
void winAiPhoto::on_PbBpEndTrain_clicked()
{
    AiThread->bpNetwork.BpNetWorkSaveData();
    AiThread->terminate();  /*end this thread*/
}

/*Start Bp Test*/
void winAiPhoto::on_PbBpStartTest_clicked()
{
    AiThread->branch = 2;
    if(AiThread->isRunning())
    {
        return;
    }
     AiThread->start(); /*Start a thread*/
}

/*End Bp Test*/
void winAiPhoto::on_PbBpEndTest_clicked()
{
    AiThread->terminate();  /*end this thread*/
}

