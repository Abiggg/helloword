#ifndef STDIMAGEBASIC_H
#define STDIMAGEBASIC_H

#include <QWidget>

#include "stddatatype.h"
#include "stdqtcvfile.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "mathfun.h"

using namespace cv;
using namespace std;

class stdImageBasic : public QWidget
{
      Q_OBJECT

public:
    stdImageBasic();
     uint32 ImageBinary(Mat matIn, QImage& QImgOut, uint32 BinaryThrehold);
     uint32 ImageGrayscal(Mat matIn, QImage& QImgOut);
     uint32 ImageEquration(Mat matIn, QImage& QImgOut);
     uint32 ImageYminor(Mat matIn, QImage& QImgOut);
     uint32 ImageXminor(Mat matIn, QImage& QImgOut);
     uint32 ImageRatation(Mat matIn, QImage& QImgOut, int angle);
     uint32 ImageFuzzyAverage(Mat matIn, QImage& QImgOut, uint8 FilterSize);
     uint32 ImageGaussian(Mat matIn, QImage& QImgOut, uint8 FilterSize);
     uint32 ImageScalar(Mat matIn, QImage& QImgOut, uint8 FilterSize);
     uint32 ImageShapen(Mat matIn, QImage& QImgOut, uint8 RatioShapen);
     uint32 ImageBrightness(Mat matIn, QImage& QImgOut, int RatioBrightness);
     uint32 ImageConstrast(Mat matIn, QImage& QImgOut, int RatioConstrast);
     uint32 ImageSaturation(Mat matIn, QImage& QImgOut, int SaturationConstrast);
     uint32 ImageClassical(Mat matIn, QImage& QImgOut);
     uint32 ImageSketch(Mat matIn, QImage& QImgOut, int SketchThrehold);
     uint32 ImageOilPaint(Mat matIn, QImage& QImgOut, uint32 FilterSize);
     uint32 ImageCorrosion(Mat matIn, QImage& QImgOut, uint32 FilterSize);
     uint32 ImageExpand(Mat matIn, QImage& QImgOut, uint32 FilterSize);
     uint32 ImageFFtHighPass(Mat matIn, QImage& QImgOut);
     uint32 ImageCvFFtLowPass(Mat matIn, QImage& QImgOut, int CutOff);
     uint32 ImageCvFFtHighPass(Mat matIn, QImage& QImgOut, int CutOff);
     uint32 ImageCvFFtBandPass(Mat matIn, QImage& QImgOut, int CutOff0, int CutOff1);
public:
     Mat matOut;
private:
    QtCvFile QtCv;
    MathFun mathfun;


protected:

};

#endif // STDIMAGEBASIC_H
