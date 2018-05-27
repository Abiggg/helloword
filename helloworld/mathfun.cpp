#include "mathfun.h"
#include "math.h"


MathFun::MathFun()
{
}
int MathFun::Binary(int x)
{
    if( x<=122)
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

unsigned int MathFun::CoutClassical(uint32 RgbSrc[], uint32 RgbDst[])
{
    RgbDst[0] = (uint32)(0.272*(float)RgbSrc[2] + 0.534*(float)RgbSrc[1] + 0.131*(float)RgbSrc[0]);
    RgbDst[1] = (uint32)(0.349*(float)RgbSrc[2] + 0.686*(float)RgbSrc[1] + 0.168*(float)RgbSrc[0]);
    RgbDst[2] = (uint32)(0.393*(float)RgbSrc[2] + 0.769*(float)RgbSrc[1] + 0.189*(float)RgbSrc[0]);
    return OK;
}

