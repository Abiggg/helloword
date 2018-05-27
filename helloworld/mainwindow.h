#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include "stdqtcvfile.h"

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

public:
    Mat srcMat;
    QImage srcQImg;

private slots:
    void reshow();
    void on_PbPhotoGraph_clicked();

    void on_PbImageTransform_3_clicked();

    void on_PbImageMorphology_clicked();

private:
    Ui::MainWindow *ui;
    QtCvFile QtCv;
};

#endif // MAINWINDOW_H
