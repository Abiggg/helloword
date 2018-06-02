#include "mathfun.h"
#include "math.h"


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

unsigned int MathFun::CountRatationSize(Mat matIn, float radian, unsigned int width, unsigned int height)
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
    SrcXY0.y = SrcRows/2;
    SrcXY0.x = SrcCols/2;
    SrcXY1.y = SrcRows/2;
    SrcXY1.x = -SrcCols/2;
    SrcXY2.y = -SrcRows/2;
    SrcXY2.x = -SrcCols/2;
    SrcXY3.y = -SrcRows/2;
    SrcXY3.x = SrcCols/2;

    DstXY0.x = SrcXY0.x * cos(radian) - SrcXY0.y*sin(radian);
    DstXY0.y = SrcXY0.x * sin(radian) + SrcXY0.y*sin(radian);
    DstXY1.x = SrcXY1.x * cos(radian) - SrcXY1.y*sin(radian);
    DstXY1.y = SrcXY1.x * sin(radian) + SrcXY1.y*sin(radian);
    DstXY2.x = SrcXY2.x * cos(radian) - SrcXY2.y*sin(radian);
    DstXY2.y = SrcXY2.x * sin(radian) + SrcXY2.y*sin(radian);
    DstXY3.x = SrcXY3.x * cos(radian) - SrcXY3.y*sin(radian);
    DstXY3.y = SrcXY3.x * sin(radian) + SrcXY3.y*sin(radian);

    width = MAXVALUE(abs(DstXY0.x - DstXY2.x),abs(DstXY1.x - DstXY3.x));
    height = MAXVALUE(abs(DstXY0.y - DstXY2.y),abs(DstXY1.y - DstXY3.y));

    return OK;
}

/*init FFT filter*/
unsigned int MathFun::initFFT(Mat MatIn, Mat &InitMat)
{
    int i = 0;
    int j = 0;
    int chl = 0;
    for(chl=0;chl<MatIn.channels();chl++)
    {
        for(i=0;i<MatIn.rows;i++)
        {
            for(j=0;j<MatIn.cols;j++)
            {
                InitMat.at<Vec3f>(i,j*2)[chl] =(float) MatIn.at<Vec3b>(i,j)[chl];
                InitMat.at<Vec3f>(i,j*2+1)[chl] =(float) MatIn.at<Vec3b>(i,j)[chl] * (-1);
            }
        }
    }
    return OK;
}

/*fft transform*/
unsigned int MathFun::fftFun(Mat InitMat, Mat &fftMat)
{
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int height = InitMat.rows;
    int width = InitMat.cols;
    double angle;

    for(i=0;i<InitMat.rows;i++)
    {
        for(j=0;InitMat.cols/2;j++)
        {
            for(m=0;m<height;m++)
            {
                for(n=0;n<width;n++)
                {
                    angle = 2*PI*((double)i*m/width + (double)j*n/height);
                    fftMat.at<Vec3f>(i,2*j) += InitMat.at<Vec3f>(i,j) * cos(angle);
                    fftMat.at<Vec3f>(i,2*j+1) += InitMat.at<Vec3f>(i,j) * sin(angle);
                }
            }
        }
    }
    return OK;
}
#if 0
unsigned int MathFun::fftSpectrum(Mat fftMat, Mat &fftSpecMat)
{
    int i = 0;
    int j = 0;
    double norm;

    for(i=0;i<fftMat.rows;i++)
    {
        for(j=0;fftMat.cols;j++)
        {
            norm = (double)fftMat.at<Vec3f>(i,2*j);
        }
    }
    return OK;
}
#endif



/**/
