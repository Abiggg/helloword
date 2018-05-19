#ifndef STDIMAGEBASIC_H
#define STDIMAGEBASIC_H

#include <QWidget>

#include "stddatatype.h"
#include "stdqtcvfile.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class stdImageBasic : public QWidget
{
      Q_OBJECT

public:
    stdImageBasic();

     uint32 ImageFuzzyAverage(Mat matIn, QImage* QImgOut, uint8 FilterSize);
     uint32 ImageGaussian(Mat matIn, QImage* QImgOut, uint8 FilterSize);

private:
    QtCvFile QtCv;
    Mat BlueMat;
    Mat GreenMat;
    Mat RedMat;
    Mat MergeDestMat;

protected:

};

#endif // STDIMAGEBASIC_H
