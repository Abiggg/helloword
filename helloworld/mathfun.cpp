#include "mathfun.h"
#include "math.h"
#include <iostream>

MathFun::MathFun()
{
}
int MathFun::Binary(int x, uint32 Binarythresholds)
{
    if( x<=(int)Binarythresholds)
    {
        return 0;
    }
    else
    {
        return 255;
    }
}

int MathFun::DataTranstrom(float x)
{
    if(fabs(x) > 255)
    {
        return (int)255;
    }
    else
    {
        return (int)fabs(x);
    }
}

int MathFun::LinerFun(int x)
{
    return x;
}

float MathFun::GaussianFun(int x, int y, uint8 FilterSize, float sigma)
{
    /*G(x,y) = 1/(2*pi*sigma^2)*e^(-(x^2+y^2)/(2*sigma^2))*/
    float gaussian_temp;
    gaussian_temp = exp(-(pow(x-FilterSize/2,2)+pow(y-FilterSize/2,2))/(2*pow(sigma,2)))/(2*PI*pow(sigma,2));
    return gaussian_temp;
}

float MathFun::GaussianFilterFun(int x, int y, int centerX, int centerY, int CutOff)
{
    float temp;
    float d;
    float d0;
    d = pow((x - centerX), 2.0) + pow((y - centerY), 2.0);
    d0 = pow((CutOff - centerX), 2.0) + pow((CutOff - centerY), 2.0);
    //temp = exp(-pow(d,2) / (pow(d0,2)));
    if(d > d0)
    {
        temp = 0;
    }
    else
    {
        temp = 1;
    }
    return temp;
}

int MathFun::PixLimit(int x)
{
    if(x > 255)
    {
        return 255;
    }
    else if(x < 0)
    {
        return 0;
    }
    else
    {
        return x;
    }

}

uint32 MathFun::CountRgbMean(Mat MatIn, unsigned char RgbMean[])
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 chl = 0;
    if(MatIn.channels()==1)
    {
        for(i=0;i<MatIn.rows;i++)
        {
            for(j=0;j<MatIn.cols;j++)
            {
               RgbMean[0] +=  MatIn.at<uchar>(i,j);
            }
        }
        RgbMean[0] = (uint8)RgbMean[0]/(MatIn.rows*MatIn.cols);
    }
    else if(MatIn.channels()==3)
    {
        for(chl=0;chl<MatIn.channels();chl++)
        {
            for(i=0;i<MatIn.rows;i++)
            {
                for(j=0;j<MatIn.cols;j++)
                {
                   RgbMean[chl] +=  MatIn.at<Vec3b>(i,j)[chl];
                }
            }
        }
        RgbMean[0] = (uint8)RgbMean[0]/(MatIn.rows*MatIn.cols);
        RgbMean[1] = (uint8)RgbMean[1]/(MatIn.rows*MatIn.cols);
        RgbMean[2] = (uint8)RgbMean[1]/(MatIn.rows*MatIn.cols);
    }
    else
    {
        return ERROR;
    }
    return OK;
}

unsigned int MathFun::CountRgbMaxMin(Mat MatIn, unsigned char RgbMax[], unsigned char RgbMin[])
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 chl = 0;

    if(MatIn.channels()==1)
    {
        RgbMax[0] = MatIn.at<uchar>(0,0);
        RgbMin[0] = MatIn.at<uchar>(0,0);
        for(i=0;i<MatIn.rows;i++)
        {
            for(j=0;j<MatIn.cols;j++)
            {
               if(RgbMax[0] < MatIn.at<uchar>(i,j))
               {
                   RgbMax[0] = MatIn.at<uchar>(i,j);
               }
               if(RgbMin[0] > MatIn.at<uchar>(i,j))
               {
                   RgbMin[0] = MatIn.at<uchar>(i,j);
               }
            }
        }
    }
    else if(MatIn.channels()==3)
    {
        for(chl=0;chl<MatIn.channels();chl++)
        {
            RgbMax[chl] = MatIn.at<Vec3b>(0,0)[chl];
            RgbMin[chl] = MatIn.at<Vec3b>(0,0)[chl];
            for(i=0;i<MatIn.rows;i++)
            {
                for(j=0;j<MatIn.cols;j++)
                {
                   if(RgbMax[chl] < MatIn.at<Vec3b>(i,j)[chl])
                   {
                       RgbMax[chl] = MatIn.at<Vec3b>(i,j)[chl];
                   }
                   if(RgbMin[chl] > MatIn.at<Vec3b>(i,j)[chl])
                   {
                       RgbMin[chl] = MatIn.at<Vec3b>(i,j)[chl];
                   }
                }
            }
        }
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/*Count classical style*/
unsigned int MathFun::CoutClassical(uint32 RgbSrc[], uint32 RgbDst[])
{
    RgbDst[0] = (uint32)(0.272*(float)RgbSrc[2] + 0.534*(float)RgbSrc[1] + 0.131*(float)RgbSrc[0]);
    RgbDst[1] = (uint32)(0.349*(float)RgbSrc[2] + 0.686*(float)RgbSrc[1] + 0.168*(float)RgbSrc[0]);
    RgbDst[2] = (uint32)(0.393*(float)RgbSrc[2] + 0.769*(float)RgbSrc[1] + 0.189*(float)RgbSrc[0]);
    return OK;
}

/*Coodinate ratation*/
unsigned int MathFun::CoordinateRatation(CoordinateXY_S SrcXY, CoordinateXY_S& DstXY, float radian)
{
    DstXY.x = SrcXY.x * cos(radian) - SrcXY.y * sin(radian);
    DstXY.y = SrcXY.x * sin(radian) + SrcXY.y * cos(radian);

    return OK;
}

unsigned int MathFun::CountRatationSize(Mat matIn, float radian, unsigned int& width, unsigned int& height)
{
    int SrcRows = matIn.rows;  /*height*/
    int SrcCols = matIn.cols;  /*width*/

    CoordinateXY_S SrcXY0, SrcXY1, SrcXY2, SrcXY3;
    CoordinateXY_S DstXY0, DstXY1, DstXY2, DstXY3;
    /*
      (x1,y1) | (x0,y0)     (x1,y1) | (x0,y0)     x = x0*cos(angel) - y0*sin(angle)
     ------------------- = -------------------
      (x2,y2) | (x3,y3)     (x2,y2) | (x3,y3)     y = x0*sin(angle) + y0*cos(angle)
    */
    SrcXY0 = {SrcCols/2, SrcRows/2};
    SrcXY1 = {-SrcCols/2, SrcRows/2};
    SrcXY2 = {-SrcCols/2, -SrcRows/2};
    SrcXY3 = {SrcCols/2, -SrcRows/2};

    CoordinateRatation(SrcXY0, DstXY0, radian);
    CoordinateRatation(SrcXY1, DstXY1, radian);
    CoordinateRatation(SrcXY2, DstXY2, radian);
    CoordinateRatation(SrcXY3, DstXY3, radian);

    width = MAXVALUE(abs(DstXY0.x - DstXY2.x),abs(DstXY1.x - DstXY3.x));
    height = MAXVALUE(abs(DstXY0.y - DstXY2.y),abs(DstXY1.y - DstXY3.y));

    return OK;
}

Mat MathFun::initFFT2(Mat &src)
{
    Mat out = Mat::zeros(cvSize(src.cols, src.rows), CV_32FC1);
    int i, j;

    for(i=0;i<src.rows;i++){
        float *ptr1 = out.ptr<float>(i);
        uchar *ptr2 = src.ptr(i);
        for(j=0;j<src.cols;j++){
            ptr1[j] = ptr2[j];
        }
    }

    for(i=0;i<src.rows;i++){
        float *ptr1 = out.ptr<float>(i);
        for(j=0;j<src.cols;j++){
            ptr1[j] = ptr1[j] * pow(-1,i+j);
        }
    }

    return out;
}

void MathFun::FFT2(Mat &TD, Mat &FD)
{
    // 循环变量
    int i, j, m ,n;
    int width = TD.cols;
    int height = TD.rows;
    Mat tmpFd = Mat::zeros(cvSize(width, height), CV_32FC2);
    double _2Pi = 2 * 3.1415926;
    double angle;

    //灰度
    for(i=0;i<width;i++){
        float *ptr1 = tmpFd.ptr<float>(i);
        for(j=0;j<height;j++){
            for(m=0;m<width;m++){
                float *ptr2 = TD.ptr<float>(m);
                for(n=0;n<height;n++){
                    angle = _2Pi * ((double)i*m / width + (double)j*n/height);
                    ptr1[j*2]   += ptr2[n] * cos(angle);
                    ptr1[j*2+1] += ptr2[n] * sin(angle);
                }
            }
        }
        //printf("i:%d\n", i);
    }
    FD = tmpFd;
}

void MathFun::IFFT2(Mat &src, Mat &dst)
{
    // 循环变量
    int i, j, m ,n;
    int width = src.cols;
    int height = src.rows;
    Mat tmpFd = Mat::zeros(cvSize(width, height), CV_32FC1);
    double _2Pi = 2 * 3.1415926;
    double angle;

    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            for(m=0;m<width;m++){
                for(n=0;n<height;n++){
                    angle = _2Pi * ((double)i*m / width + (double)j*n/height);
                    tmpFd.at<float>(i,j) += src.at<float>(width-m,(height - n)*2) * cos(angle)
                                - src.at<float>(width-m, (height-n)*2+1) * sin(angle);
                }
            }
            tmpFd.at<uchar>(i, j) = tmpFd.at<float>(i, j) / width / height;
        }
        //printf("i:%d\n", i);
    }
    dst = tmpFd;
}




