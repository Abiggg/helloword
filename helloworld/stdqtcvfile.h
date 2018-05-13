#ifndef QTCVFILE_H
#define QTCVFILE_H
#include <QWidget>

#include "stddatatype.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class QtCvFile : public QWidget
{    
    Q_OBJECT

    public:
        QtCvFile();  //construction function

        uint32 OpenImageFile(Mat *image);  //Open image File
        uint32 SaveImageFile(Mat image);  //Save image File
        uint32 cvMat2QImage(Mat& mat, QImage& image); //convert mat to QImage
        Mat QImage2cvMat(QImage image); //convert image to Mat

    private:

    protected:


};

#endif // QTCVFILE_H
