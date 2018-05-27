#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdbool.h>

#include "winimagetransform.h"
#include "winimagefuzzy.h"
#include "winimagestrength.h"
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
void MainWindow::on_PbImageTransform_clicked()
{
    this->hide();//主界面关闭
    WinImageTransform *Transform = new WinImageTransform();//新建子界面
    connect(Transform,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    Transform->show();//子界面出现
}

/*image Fuzzy*/
void MainWindow::on_PbImageFuzzy_clicked()
{
    this->hide();//主界面关闭
    WinImageFuzzy *fuzzy = new WinImageFuzzy();//新建子界面
    connect(fuzzy,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    QPixmapCache::setCacheLimit(1);
    fuzzy->FilterSize = 1;
    fuzzy->show();//子界面出现
}

/*image Segmetation*/
void MainWindow::on_PbImageStrength_clicked()
{
    this->hide();//主界面关闭
    WinImageStrength *fuzzy = new WinImageStrength();//新建子界面
    connect(fuzzy,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    fuzzy->show();//子界面出现
}


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
