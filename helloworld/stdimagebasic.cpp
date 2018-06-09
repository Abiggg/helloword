#include "stdimagebasic.h"
#include <iostream>

using namespace cv;
using namespace std;

stdImageBasic::stdImageBasic()
{

}

unsigned int stdImageBasic::ImageBinary(Mat matIn, QImage& QImgOut, uint32 BinaryThrehold)
{
     Mat matOutTemp;

     CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
     CHECK_CODE(QtCv.BinaryTransform(matIn, matOutTemp, BinaryThrehold), ERROR_CODE_1); /*init Filter*/
     CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

     matOut = matOutTemp.clone();
     return OK;
}

unsigned int stdImageBasic::ImageGrayscal(Mat matIn, QImage& QImgOut)
{
    Mat matOutTemp;

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.GrayscalTransform(matIn, matOutTemp), ERROR_CODE_1); /*init Filter*/
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageEquration(Mat matIn, QImage& QImgOut)
{
    int Equation[3][255] = {0};
    Mat matOutTemp;

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.CountHistogram(matIn, Equation), ERROR_CODE_1);
    CHECK_CODE(QtCv.HistogramTransform(matIn, Equation, matOutTemp), ERROR_CODE_2);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_3);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageYminor(Mat matIn, QImage& QImgOut)
{
    Mat matOutTemp;

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.MinorYTransform(matIn, matOutTemp), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_3);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageXminor(Mat matIn, QImage &QImgOut)
{
    Mat matOutTemp = Mat::zeros(matIn.rows, matIn.cols, CV_8UC3);

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.MinorXTransform(matIn, matOutTemp), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageRatation(Mat matIn, QImage &QImgOut, int angle)
{
    Mat matOutTemp;
    Mat matOutTemp2;
    CHECK_CODE(QtCv.RatationTransform(matIn, matOutTemp, angle), ERROR_CODE_0);
    CHECK_CODE(QtCv.CreatTempMat(matOutTemp, matOutTemp2), ERROR_CODE_1);
    CHECK_CODE(QtCv.NearInterTransform(matOutTemp, matOutTemp2), ERROR_CODE_2);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp2, QImgOut), ERROR_CODE_3);/*convert mat into qimage*/

    matOut = matOutTemp2.clone();
    return OK;

}

uint32 stdImageBasic::ImageFuzzyAverage(Mat matIn, QImage& QImgOut, uint8 FilterSize)
{
    uint32 sum[3] = {0};
    Mat matOutTemp;
    Mat Filter;

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.CreatTempFilter(matIn, FilterSize, Filter), ERROR_CODE_1);
    CHECK_CODE(QtCv.AverageFilter(FilterSize, sum, Filter), ERROR_CODE_2); /*init Filter*/
    CHECK_CODE(QtCv.FilterCountAverage(matIn, matOutTemp, sum, Filter), ERROR_CODE_3); /*Filter*/
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_4);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

uint32 stdImageBasic::ImageGaussian(Mat matIn, QImage& QImgOut, uint8 FilterSize)
{
    uint32 sum[3] = {0};
    float sigma = 0.8;
    Mat matOutTemp;
    Mat Filter;

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.CreatTempFilter(matIn, FilterSize, Filter), ERROR_CODE_1);
    CHECK_CODE(QtCv.GaussianFilter(FilterSize, sum, sigma, Filter), ERROR_CODE_2);
    CHECK_CODE(QtCv.FilterCountAverage(matIn, matOutTemp, sum, Filter), ERROR_CODE_3); /*Filter*/
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_4);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageScalar(Mat matIn, QImage &QImgOut, unsigned char FilterSize)
{
    Mat matOutTemp;
    Mat Filter;

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.CreatFloatFilter(matIn, FilterSize, Filter), ERROR_CODE_1);
    CHECK_CODE(QtCv.LaplaceFilter(Filter), ERROR_CODE_2);
    CHECK_CODE(QtCv.FilterCountSum(matIn, matOutTemp, Filter), ERROR_CODE_3); /*Filter*/
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_4);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageShapen(Mat matIn, QImage &QImgOut, uint8 RatioShapen)
{
    uint8 FilterSize = 3;
    Mat matOutTemp;
    Mat Filter;

    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.CreatFloatFilter(matIn, FilterSize, Filter), ERROR_CODE_1);
    CHECK_CODE(QtCv.LaplaceFilter(Filter), ERROR_CODE_2);
    CHECK_CODE(QtCv.ShapenTransform(matIn, matOutTemp, Filter, RatioShapen), ERROR_CODE_3); /*Filter*/
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_4);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageBrightness(Mat matIn, QImage &QImgOut, int RatioBrightness)
{
     Mat matOutTemp;
     CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
     CHECK_CODE(QtCv.BrightTransform(matIn, matOutTemp, RatioBrightness), ERROR_CODE_1);
     CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

     matOut = matOutTemp.clone();
     return OK;
}

unsigned int stdImageBasic::ImageConstrast(Mat matIn, QImage &QImgOut, int RatioConstrast)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.ConstrastTransform(matIn, matOutTemp, RatioConstrast), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageSaturation(Mat matIn, QImage &QImgOut, int SaturationConstrast)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.SaturationTransform(matIn, matOutTemp, SaturationConstrast), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageClassical(Mat matIn, QImage &QImgOut)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.ClassicalTransform(matIn, matOutTemp), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageSketch(Mat matIn, QImage &QImgOut, int SketchThrehold)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.SketchTransform(matIn, matOutTemp, SketchThrehold), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageOilPaint(Mat matIn, QImage &QImgOut, unsigned int FilterSize)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.OilPaintTransform(matIn, matOutTemp, FilterSize), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageCorrosion(Mat matIn, QImage &QImgOut, unsigned int FilterSize)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.CorrosionTransform(matIn, matOutTemp, FilterSize), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageExpand(Mat matIn, QImage &QImgOut, unsigned int FilterSize)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.CreatTempMat(matIn, matOutTemp), ERROR_CODE_0);
    CHECK_CODE(QtCv.ExpandTransform(matIn, matOutTemp, FilterSize), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageFFtHighPass(Mat matIn, QImage &QImgOut)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.fftTransform(matIn, matOutTemp), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageCvFFtLowPass(Mat matIn, QImage &QImgOut ,int CutOff)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.cvDFtLowTransform(matIn, matOutTemp, CutOff), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

unsigned int stdImageBasic::ImageCvFFtHighPass(Mat matIn, QImage &QImgOut, int CutOff)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.cvDFtHighTransform(matIn, matOutTemp, CutOff), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}

/*FFt Band Filter*/
unsigned int stdImageBasic::ImageCvFFtBandPass(Mat matIn, QImage &QImgOut, int CutOff0, int CutOff1)
{
    Mat matOutTemp;
    CHECK_CODE(QtCv.cvDFtBandTransform(matIn, matOutTemp, CutOff0, CutOff1), ERROR_CODE_1);
    CHECK_CODE(QtCv.cvMat2QImage(matOutTemp, QImgOut), ERROR_CODE_2);/*convert mat into qimage*/

    matOut = matOutTemp.clone();
    return OK;
}
