#include "stdimagebasic.h"
#include <iostream>

using namespace cv;
using namespace std;

stdImageBasic::stdImageBasic()
{

}

uint32 stdImageBasic::ImageFuzzyAverage(Mat matIn, QImage* QImgOut, uint8 FilterSize)
{
   // Mat matInTemp;
    Mat matOutTemp;
    uint32 sum[3] = {0};
    Mat Filter = Mat::zeros(FilterSize, FilterSize, CV_8UC3);
    //QtCv.QImage2cvMat(QImagInTemp, matInTemp); /*change qimage to mat*/
    matOutTemp = matIn;
    QtCv.AverageFilter(FilterSize, sum, Filter); /*init Filter*/
    cout<<sum[0]<<endl;
    QtCv.FilterCountAverage(matIn, matOutTemp, sum, Filter); /*Filter*/
    QtCv.cvMat2QImage(matOutTemp, *QImgOut);/*convert mat into qimage*/
    return OK;
}

uint32 stdImageBasic::ImageGaussian(Mat matIn, QImage* QImgOut, uint8 FilterSize)
{
   // Mat matInTemp;
    Mat matOutTemp;
    uint32 sum[3] = {0};
    float sigma = 0.8;
    Mat Filter = Mat::zeros(FilterSize, FilterSize, CV_8UC3);
    matOutTemp = matIn;
    QtCv.GaussianFilter(FilterSize, sum, sigma, Filter);
    cout<<sum[0]<<endl;
    cout<<Filter<<endl;
    QtCv.FilterCountAverage(matIn, matOutTemp, sum, Filter); /*Filter*/
    QtCv.cvMat2QImage(matOutTemp, *QImgOut);/*convert mat into qimage*/
    return OK;
}
