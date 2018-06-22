#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdbool.h>

#include "winbeatifyphoto.h"
#include "winaiphoto.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/video.hpp>
#include "stdqtcvfile.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BeatifyPhoto = new WinBeatifyPhoto();/*creat a image beatify win*/
    AiPhoto = new winAiPhoto();/*creat a AI photo win*/

    connect(this->BeatifyPhoto,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    connect(this->BeatifyPhoto,SIGNAL(WinAiDisplay(Mat)),AiPhoto,SLOT(gotoAiPhoto_clicked_reshow(Mat)));//当点击子界面时，调用主界面的reshow()函数

    connect(this->AiPhoto, SIGNAL(WinDisplay()), this, SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    connect(this->AiPhoto, SIGNAL(WinBeatifyDisplay(Mat)), BeatifyPhoto, SLOT(gotoBeatifyPhoto_clicked_reshow(Mat)));//当点击子界面时，调用主界面的reshow()函数
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenCamera()
{
#if 0
    Mat frame;
    VideoCapture cap(0);
    namedWindow("Live", 0);
    if(!cap.isOpened())
    {
        cout<<"camera opened failed"<<endl;
    }

    while(1)
    {
        cap>>frame;
        srcMat = frame;
        CHECK(QtCv.cvMat2QImage(frame,srcQImg));
        ui->LbCameraArea->setPixmap(QPixmap::fromImage(srcQImg));
        if(waitKey(30)>= 0)
        {
            cap.release();
            imshow("Live", frame);
            destroyWindow("Live");
            break;
        }
    }
#endif
    Mat frame;
    VideoCapture cap(0);
    ThreadMainWinInit();
    if(ThreadMainWin->isRunning())
    {
        return;
    }
     ThreadMainWin->start(); /*Start a thread*/

    if(!cap.isOpened())
    {
        cout<<"camera opened failed"<<endl;
    }

    while(1)
    {
        if(!ThreadMainWin->isPhoto)
        {
            cap>>frame;
            srcMat = frame;
            CHECK(QtCv.cvMat2QImage(frame,srcQImg));
            ui->LbCameraArea->setPixmap(QPixmap::fromImage(srcQImg));
            waitKey(30);
        }
        else
        {
            cap.release();
            ui->LbCameraArea->setPixmap(QPixmap::fromImage(srcQImg));
            ThreadMainWin->terminate();  /*end this thread*/
        }
    }

}

/*Main ai thread init*/
void MainWindow::ThreadMainWinInit()
{
    ThreadMainWin = new ThreadFromQthread();
}


void MainWindow::reshow()
{
    this->show();
}

void MainWindow::on_PbPhotoGraph_clicked()
{
    OpenCamera();
}

#if 0
void MainWindow::on_PbBeautifyPhoto_clicked()
{
    this->hide();//主界面关闭
    WinBeatifyPhoto *BeatifyPhoto = new WinBeatifyPhoto();//新建子界面
    connect(BeatifyPhoto,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数

    BeatifyPhoto->matIn = srcMat;
    BeatifyPhoto->QImgIn = srcQImg;
    if(!srcMat.empty())
    {
         BeatifyPhoto->PhotoFlag = true;
    }
    else
    {
        BeatifyPhoto->PhotoFlag = false;
    }
    BeatifyPhoto->WinInit();
    BeatifyPhoto->show();//子界面出现
}
#endif


/*open BeautifyPhoto win*/
void MainWindow::on_PbBeautifyPhoto_clicked()
{
    this->hide();//主界面关闭

    this->BeatifyPhoto->matIn = srcMat;
    this->BeatifyPhoto->QImgIn = srcQImg;
    if(!srcMat.empty())
    {
         this->BeatifyPhoto->PhotoFlag = true;
    }
    else
    {
        this->BeatifyPhoto->PhotoFlag = false;
    }
    this->BeatifyPhoto->WinInit();
    this->BeatifyPhoto->show();//子界面出现
}

/*Open AiPhoto win*/
void MainWindow::on_PbAiPhoto_clicked()
{
    this->hide();//主界面关闭
    this->AiPhoto->matIn = srcMat;
    this->AiPhoto->QImgIn = srcQImg;
    if(!srcMat.empty())
    {
         this->AiPhoto->PhotoFlag = true;
    }
    else
    {
        this->AiPhoto->PhotoFlag = false;
    }
    this->AiPhoto->winAiPhotoInit();
    this->AiPhoto->show();//子界面出现
}
