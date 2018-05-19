#ifndef QTCVFILE_H
#define QTCVFILE_H
#include <QWidget>

#include "stddatatype.h"
#include "mathfun.h"
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

        uint32 OpenImageFile(Mat& mat);  //Open image File
        uint32 SaveImageFile(Mat mat);  //Save image File
        uint32 cvMat2QImage(Mat mat, QImage& Qimg); //convert mat to QImage
        uint32 QImage2cvMat(QImage Qimg, Mat& mat); //convert image to Mat
        uint32 SplitBGRToMat(Mat mat, Mat& BlueMat, Mat& GreenMat, Mat& RedMat); //split 3 channel into 1 channel
        uint32 MergeBRGtoMat(Mat BlueMat, Mat GreenMat, Mat RedMat, Mat& mat); //merge 3 single-channel into 3 channel image
        uint32 FilterCountAverage(Mat InputMat, Mat& OutputMat, uint32 add[3], Mat Filter);
        uint32 AverageFilter(uint8 FilterSize, uint32 sum[3], Mat& Filter);
        uint32 GaussianFilter(uint8 FilterSize, uint32 sum[3], float sigma, Mat &Filter);
        uint32 LaplaceFilter(Mat &Filter);

    private:
        MathFun mathfun;
        Mat BlueMat;
        Mat GreenMat;
        Mat RedMat;

    protected:


};

#endif // QTCVFILE_H
