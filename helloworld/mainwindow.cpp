#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdbool.h>

#include "winbeatifyphoto.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenCamera()
{
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
}

void MainWindow::reshow()
{
    this->show();
}


/*image Transform*/


/*image Fuzzy*/


/*image Segmetation*/



void MainWindow::on_PbPhotoGraph_clicked()
{
    OpenCamera();
}

void MainWindow::on_PbImageTransform_3_clicked()
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

void MainWindow::on_PbImageMorphology_clicked()
{
    this->hide();//主界面关闭
    WinBeatifyPhoto *BeatifyPhoto = new WinBeatifyPhoto();//新建子界面
    connect(BeatifyPhoto,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    //BeatifyPhoto->matIn = srcMat;
    //BeatifyPhoto->QImgIn = srcQImg;
}
