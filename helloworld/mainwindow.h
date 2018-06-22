#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include "stdqtcvfile.h"
#include "winbeatifyphoto.h"
#include "winaiphoto.h"
#include "threadfromqthread.h"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void OpenCamera();
    void ThreadMainWinInit();

public:
    Mat srcMat;
    QImage srcQImg;
    WinBeatifyPhoto *BeatifyPhoto;
    winAiPhoto *AiPhoto;//新建子界面

private slots:
    void reshow();

    void on_PbPhotoGraph_clicked();

    void on_PbBeautifyPhoto_clicked();

    void on_PbAiPhoto_clicked();

private:
    Ui::MainWindow *ui;
    QtCvFile QtCv;
    ThreadFromQthread *ThreadMainWin;
};

#endif // MAINWINDOW_H
