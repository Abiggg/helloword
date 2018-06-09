#include "stdqtcvfile.h"

#include <iostream>
#include "stdqtcvfile.h"

#include "QMenu"
#include "QMenuBar"
#include "QAction"
#include "QMessageBox"
#include "QFileDialog"
#include "QDebug"
#include "mathfun.h"

using namespace cv;
using namespace std;

QtCvFile::QtCvFile()
{

}

/*Open File*/
uint32 QtCvFile::OpenImageFile(Mat& mat)
{
    //open file and return file abstract route
    QStringList    QfileNameList;
    QString QfileName;
    QFileDialog* fd = new QFileDialog();//创建对话框
    fd->resize(240,320);    //设置显示的大小
    fd->setWindowTitle("打开图片");
    fd->setNameFilter("Images(*.png *.jpg *.jpeg *.bmp)");
    fd->setFileMode(QFileDialog::ExistingFiles);
    fd->setViewMode(QFileDialog::List);  //设置浏览模式，有 列表（list） 模式和 详细信息（detail）两种方式
    if ( fd->exec() == QDialog::Accepted )   //如果成功的执行
    {
    QfileNameList = fd->selectedFiles();      //返回文件列表的名称
    QfileName = QfileNameList[0];            //取第一个文件名
    string fileName = QfileName.toStdString();
    //opencv read file and return RGB FILE
    mat = imread(fileName);//读入一站图片 暂时读入桌面上的一个文件
    //cvtColor(mat, mat, CV_BGR2RGB);//opencv读取图片按照BGR方式读取，为了正常显示，所以将BGR转为RGB
    return OK;
    }
    else
    {
     fd->close();
     return ERROR;
    }
}

/*Save File*/
uint32 QtCvFile::SaveImageFile(Mat mat)
{
    QString QfileName;
    QfileName = QFileDialog::getSaveFileName(this,
                                             tr("Save Image"),
                                             "",
                                             "Images (*.png *.bmp *.jpg *.jpeg)"); //选择路径
    string fileAsSave = QfileName.toStdString();
    imwrite(fileAsSave,mat);
    return OK;
}

/*convert Mat to QImage*/
uint32 QtCvFile::cvMat2QImage(Mat mat, QImage& Qimg)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        Qimg = QImage(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        Qimg.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            Qimg.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = Qimg.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return OK;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        Qimg = QImage(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        Qimg = Qimg.rgbSwapped();
        return OK;
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        Qimg = QImage(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return OK;
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return ERROR;
    }
    return OK;
}

/*convert QImage to Mat*/
uint32 QtCvFile::QImage2cvMat(QImage Qimg, Mat& mat)
{
    if(Qimg.format() == QImage::Format_ARGB32_Premultiplied)
    {
        mat = Mat(Qimg.height(), Qimg.width(), CV_8UC4, (void*)Qimg.constBits(), Qimg.bytesPerLine());
    }
    else if (Qimg.format() == QImage::Format_RGB888)
    {
        mat = Mat(Qimg.height(), Qimg.width(), CV_8UC3, (void*)Qimg.constBits(), Qimg.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
    }
    else if (Qimg.format() == QImage::Format_Indexed8)
    {
        mat = Mat(Qimg.height(), Qimg.width(), CV_8UC1, (void*)Qimg.constBits(), Qimg.bytesPerLine());
    }
    else
    {
        cout<<"unknow type of Qimage"<<endl;
        return ERROR;
    }
    return OK;
}

/*split image into B G R*/
uint32 QtCvFile::SplitBGRToMat(Mat mat, Mat &BlueMat, Mat &GreenMat, Mat &RedMat)
{
     vector<Mat> channels;
    split(mat,channels);
    BlueMat = channels.at(0);
    GreenMat = channels.at(1);
    RedMat = channels.at(2);
    return OK;
}

/*Merge image into single Mat*/
uint32 QtCvFile::MergeBRGtoMat(Mat BlueMat, Mat GreenMat, Mat RedMat, Mat& mat)
{
    vector<Mat> channels;
    channels.push_back(BlueMat);
    channels.push_back(GreenMat);
    channels.push_back(RedMat);
    merge(channels,mat);
    return OK;
}

/*compare two if mat is equral*/
unsigned int QtCvFile::CompareMat(Mat matA, Mat matB, int& flag)
{
    int i = 0;
    int j = 0;
    int chl = 0;
    if(matA.channels() == 1)
    {
        for(i=0;i<matA.rows;i++)
        {
            for(j=0;j<matA.cols;j++)
            {
                if(matA.at<uchar>(i,j) == matB.at<uchar>(i,j))
                {
                    continue;
                }
                else
                {
                    flag = 1;
                    return OK;
                }
            }
        }
        flag = 0;
    }
    else if(matA.channels() == 3)
    {
        for(chl=0;chl<matA.channels();chl++)
        {
            for(i=0;i<matA.rows;i++)
            {
                for(j=0;j<matA.cols;j++)
                {
                    if(matA.at<Vec3b>(i,j)[chl] == matB.at<Vec3b>(i,j)[chl])
                    {
                        continue;
                    }
                    else
                    {
                        flag = 1;
                        return OK;
                    }
                }
            }
        }
        flag = 0;
    }
    return OK;
}

/*Creat Temp Mat*/
unsigned int QtCvFile::CreatTempMat(Mat InputMat, Mat &OutputMat)
{
    if(InputMat.channels() == 1)
    {
        OutputMat = Mat::zeros(InputMat.rows, InputMat.cols, CV_8UC1);
    }
    else if(InputMat.channels() == 3)
    {
        OutputMat = Mat::zeros(InputMat.rows, InputMat.cols, CV_8UC3);
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/*Creat Temp Filter*/
unsigned int QtCvFile::CreatTempFilter(Mat InputMat, uint8 FilterSize, Mat &Filter)
{
    if(InputMat.channels() == 1)
    {
        Filter = Mat::zeros(FilterSize, FilterSize, CV_8UC1);
    }
    else if(InputMat.channels() == 3)
    {
        Filter = Mat::zeros(FilterSize, FilterSize, CV_8UC3);
    }
    else
    {
        return ERROR;
    }
    return OK;
}

unsigned int QtCvFile::CreatFloatFilter(Mat InputMat, unsigned int FilterSize, Mat &Filter)
{
    if(InputMat.channels() == 1)
    {
        Filter = Mat::zeros(FilterSize, FilterSize, CV_32FC3);
    }
    else if(InputMat.channels() == 3)
    {
        Filter = Mat::zeros(FilterSize, FilterSize, CV_32FC3);
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/*Average Filter*/
uint32 QtCvFile::AverageFilter(uint8 FilterSize, uint32 sum[3], Mat& Filter)
{
    uint32 i;
    uint32 j;
    for(i=0;i<FilterSize;i++)
    {
        for(j=0;j<FilterSize;j++)
        {
            Filter.at<Vec3b>(i,j)[0] = 1;
            sum[0] = sum[0] + 1;
            Filter.at<Vec3b>(i,j)[1] = 1;
            sum[1] = sum[1] + 1;
            Filter.at<Vec3b>(i,j)[2] = 1;
            sum[2] = sum[2] + 1;
        }
    }
    return OK;
}

/*Gaussian Filter*/
unsigned int QtCvFile::GaussianFilter(unsigned char FilterSize, unsigned int sum[3], float sigma, Mat &Filter)
{
    uint32 i;
    uint32 j;
    uint32 chl;
    float normalization;
    for(chl=0;chl<3;chl++)
    {
         normalization = mathfun.GaussianFun(0,0,FilterSize,sigma);
        for(i=0;i<FilterSize;i++)
        {
            for(j=0;j<FilterSize;j++)
            {
                Filter.at<Vec3b>(i,j)[chl] = mathfun.GaussianFun(i,j,FilterSize,sigma)/normalization;
                sum[chl] += Filter.at<Vec3b>(i,j)[chl];
            }
        }
    }
    return OK;
}

/*Laplace Filter*/
unsigned int QtCvFile::LaplaceFilter(Mat &Filter)
{
    uint32 i;
    uint32 j;
    uint32 chl;
    for(chl=0;chl<3;chl++)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i == 1 && j == 1)
                {
                    Filter.at<Vec3f>(i,j)[chl] = -8.0;
                }
                else
                {
                    Filter.at<Vec3f>(i,j)[chl] = 1.0;
                }
            }
        }
    }
    return OK;
}

/*CountHistogram*/
unsigned int QtCvFile::CountHistogram(Mat InputMat, int distribution[3][255])
{
    int i=0;
    int j=0;
    int chl = 0;
    int temp = 0;
    for(chl=0;chl<InputMat.channels();chl++)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                temp = InputMat.at<Vec3b>(i,j)[chl];
                distribution[chl][temp] += 1;
            }
        }
    }
    return OK;
}

/*HistogramTransform*/
unsigned int QtCvFile::HistogramTransform(Mat InputMat, int distribution[3][255], Mat &OutputMat)
{
    int i=0;
    int j=0;
    int chl = 0;
    int temp[3][255] = { 0 };
    int value = 0;
    int pix = InputMat.rows * InputMat.cols;
    float sum = 0;
    for(chl=0;chl<3;chl++)
    {
        for(i=0;i<255;i++)
        {
           sum += distribution[chl][i] * 255.0 / pix;
           temp[chl][i] = mathfun.PixLimit((int)sum);
           //cout<<temp[chl][i]<<endl;
        }
        sum = 0;
    }
    for(chl=0;chl<3;chl++)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j = 0;j<InputMat.cols;j++)
            {
                value = InputMat.at<Vec3b>(i,j)[chl];
                OutputMat.at<Vec3b>(i,j)[chl] = temp[chl][value];
            }
        }
    }
    return OK;
}

/*************************************************************************************************/

/*HistogramTransform*/
uint32 QtCvFile::BinaryTransform(Mat InputMat, Mat &OutputMat, uint32 BinaryThrehold)
{
    int i=0;
    int j=0;
    int chl = 0;
    for(chl=0;chl<InputMat.channels();chl++)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                if(InputMat.channels() == 1)
                {
                    OutputMat.at<uchar>(i,j) =mathfun.Binary(InputMat.at<uchar>(i,j), BinaryThrehold);
                }
                else if(InputMat.channels() == 3)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] =mathfun.Binary(InputMat.at<Vec3b>(i,j)[chl], BinaryThrehold);
                }
                else
                {
                    return ERROR;
                }
            }
        }
    }
    return OK;
}

/*GrayscalTransform*/
unsigned int QtCvFile::GrayscalTransform(Mat InputMat, Mat &OutputMat)
{
    if(InputMat.channels() == 1)
    {
        return OK;
    }
    else if(InputMat.channels() == 3)
    {
         cvtColor(InputMat, OutputMat, CV_BGR2GRAY);
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/*DataTypeTransform*/
unsigned int QtCvFile::DataTypeTransform(Mat InputMat, Mat &OutputMat)
{
    int i=0;
    int j=0;
    int chl = 0;
    for(chl=0;chl<InputMat.channels();chl++)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                if(InputMat.channels() == 1)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = mathfun.DataTranstrom((int)InputMat.at<Vec3f>(i,j)[chl]);
                }
                else if(InputMat.channels() == 3)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = mathfun.DataTranstrom((int)InputMat.at<Vec3f>(i,j)[chl]);
                }
                else
                {
                    return ERROR;
                }

            }

        }
    }
    return OK;
}

/*MinorY*/
unsigned int QtCvFile::MinorYTransform(Mat InputMat, Mat &OutputMat)
{
    int i=0;
    int j=0;
    int chl = 0;
    if(InputMat.channels() == 1)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols/2;j++)
                {
                    OutputMat.at<uchar>(i,j) = InputMat.at<uchar>(i,InputMat.cols-j-1);
                    OutputMat.at<uchar>(i,InputMat.cols-j-1) = InputMat.at<uchar>(i,j);
                }
                if(InputMat.cols/2)
                {
                    OutputMat.at<uchar>(i,InputMat.cols/2) = InputMat.at<uchar>(i,InputMat.cols/2);
                }
            }
        }
    }
    else if(InputMat.channels() == 3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols/2;j++)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = InputMat.at<Vec3b>(i,InputMat.cols-j-1)[chl];
                    OutputMat.at<Vec3b>(i,InputMat.cols-j-1)[chl] = InputMat.at<Vec3b>(i,j)[chl];
                }
                if(InputMat.cols/2)
                {
                    OutputMat.at<Vec3b>(i,InputMat.cols/2)[chl] = InputMat.at<Vec3b>(i,InputMat.cols/2)[chl];
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

/*MinorX*/
unsigned int QtCvFile::MinorXTransform(Mat InputMat, Mat &OutputMat)
{
    int i=0;
    int j=0;
    int chl = 0;
    if(InputMat.channels()==1)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.cols;i++)
            {
                for(j=0;j<InputMat.rows/2;j++)
                {
                    OutputMat.at<uchar>(j,i)= InputMat.at<uchar>(InputMat.rows-j-1, i);
                    OutputMat.at<uchar>(InputMat.rows-j-1, i) = InputMat.at<uchar>(j, i);
                }
                if(InputMat.rows/2)
                {
                    OutputMat.at<uchar>(InputMat.rows/2, i) = InputMat.at<uchar>(InputMat.rows/2, i);
                }
            }
        }
    }
    else if(InputMat.channels()==3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.cols;i++)
            {
                for(j=0;j<InputMat.rows/2;j++)
                {
                    OutputMat.at<Vec3b>(j,i)[chl] = InputMat.at<Vec3b>(InputMat.rows-j-1, i)[chl];
                    OutputMat.at<Vec3b>(InputMat.rows-j-1, i)[chl] = InputMat.at<Vec3b>(j, i)[chl];
                }
                if(InputMat.rows/2)
                {
                    OutputMat.at<Vec3b>(InputMat.rows/2, i)[chl] = InputMat.at<Vec3b>(InputMat.rows/2, i)[chl];
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

/*ratation transform*/
unsigned int QtCvFile::RatationTransform(Mat InputMat, Mat &OutputMat, int angle)
{
    int i = 0;
    int j = 0;
    int chl = 0;
    uint32 width = 0;
    uint32 height = 0;
    float radian = RADIAN(angle);
    int x = 0;
    int y = 0;

    mathfun.CountRatationSize(InputMat, radian, width, height); /*Count size after ratation*/
    if(InputMat.channels() == 1)
    {
         OutputMat = Mat::zeros(height, width, CV_8UC1);
         for(i=0;i<InputMat.rows;i++)
         {
             for(j=0;j<InputMat.cols;j++)
             {
                 x = abs(((j - InputMat.cols/2))*cos(radian) - ((-i + InputMat.rows/2))*sin(radian) + width/2);
                 y = abs(((j - InputMat.cols/2))*sin(radian) + ((-i + InputMat.rows/2))*cos(radian) - height/2);
                  OutputMat.at<uchar>(y, x) = InputMat.at<uchar>(i, j);
             }
         }
    }
    else if(InputMat.channels() == 3)
    {
         OutputMat = Mat::zeros(height, width, CV_8UC3);
         for(chl=0;chl<InputMat.channels();chl++)
         {
             for(i=0;i<InputMat.rows;i++)
             {
                 for(j=0;j<InputMat.cols;j++)
                 {
                      x = abs(((j - InputMat.cols/2))*cos(radian) - ((-i + InputMat.rows/2))*sin(radian) + width/2);
                      y = abs(((j - InputMat.cols/2))*sin(radian) + ((-i + InputMat.rows/2))*cos(radian) - height/2);
                      OutputMat.at<Vec3b>(y, x)[chl] = InputMat.at<Vec3b>(i, j)[chl];
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

/*Bright Transform*/
unsigned int QtCvFile::BrightTransform(Mat InputMat, Mat &OutputMat, unsigned int RatioBrightness)
{
    int i=0;
    int j = 0;
    int chl = 0;
    float floartRatioBrightness = (RatioBrightness - 100.0)/100.0*128.0;
    //uint8 RgbMean[3] = {0};
    //mathfun.CountRgbMean(InputMat,RgbMean);

    if(InputMat.channels()==1)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                //OutputMat.at<uchar>(i,j) = mathfun.PixLimit((int)(InputMat.at<uchar>(i,j) + floartRatioBrightness*RgbMean[0]));
                OutputMat.at<uchar>(i,j) = mathfun.PixLimit((int)(InputMat.at<uchar>(i,j) + (int)floartRatioBrightness));
            }
        }
    }
    else if(InputMat.channels()==3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols;j++)
                {
                   // OutputMat.at<Vec3b>(i,j)[chl] = mathfun.PixLimit((int)(InputMat.at<Vec3b>(i,j)[chl] + floartRatioBrightness*RgbMean[chl]));
                    OutputMat.at<Vec3b>(i,j)[chl] = mathfun.PixLimit((int)(InputMat.at<Vec3b>(i,j)[chl] + (int)floartRatioBrightness));                }
            }
        }
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/*Constrast Transform*/
unsigned int QtCvFile::ConstrastTransform(Mat InputMat, Mat &OutputMat, unsigned int RatioConstrast)
{
    int i=0;
    int j = 0;
    int chl = 0;
    float floartRatioConstrast = (RatioConstrast - 100.0)/100.0;

    if(InputMat.channels()==1)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                OutputMat.at<uchar>(i,j) = mathfun.PixLimit(((float)InputMat.at<uchar>(i,j) - 128.0) * floartRatioConstrast + (float)InputMat.at<uchar>(i,j));
            }
        }
    }
    else if(InputMat.channels()==3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols;j++)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = mathfun.PixLimit(((float)InputMat.at<Vec3b>(i,j)[chl] - 128.0) * floartRatioConstrast + \
                                                                     (float)(InputMat.at<Vec3b>(i,j)[chl]));
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

/*SaturationTransform*/
unsigned int QtCvFile::SaturationTransform(Mat InputMat, Mat &OutputMat, unsigned int RatioSaturation)
{
    int i=0;
    int j = 0;
    int chl = 0;
    float floartRatioConstrast = (RatioSaturation - 100.0)/100.0;

    uint8 RgbMax[3] = {0};
    uint8 RgbMin[3] = {0};

    float DeltaRgb[3] = {0};
    float AverageRgb[3] = {0};

    float Lightness[3] = {0};
    float Saturation[3] = {0};
    float alpha[3] = {0};

    mathfun.CountRgbMaxMin(InputMat, RgbMax, RgbMin);

    if(InputMat.channels()==1)
    {
        DeltaRgb[0] = (RgbMax[0] - RgbMin[0])/255.0;
        AverageRgb[0] = (RgbMax[0] + RgbMin[0])/255.0;
        Lightness[0] = AverageRgb[0]/2.0;

        if(Lightness[0] > 0.5)
        {
            Saturation[0] = DeltaRgb[0]/AverageRgb[0];
        }
        else
        {
            Saturation[0] = DeltaRgb[0]/(2-AverageRgb[0]);
        }

        if(floartRatioConstrast > 0)
        {
            if((floartRatioConstrast + Saturation[0])>=1)
            {
                alpha[0] = Saturation[0];
            }
            else
            {
                alpha[0] = 1 - floartRatioConstrast;
            }
            alpha[0] = 1/alpha[0] -1;
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols;j++)
                {
                    OutputMat.at<uchar>(i,j) = mathfun.PixLimit(((float)InputMat.at<uchar>(i,j) - Lightness[0]*255.0) * alpha[0] + (float)InputMat.at<uchar>(i,j));
                }
            }
        }
        else
        {
            alpha[0] = floartRatioConstrast;
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols;j++)
                {
                    OutputMat.at<uchar>(i,j) = mathfun.PixLimit(((float)InputMat.at<uchar>(i,j) - Lightness[0] * 255.0) * (alpha[0] + 1) + Lightness[0]*255.0);
                }
            }
        }

    }
    else if(InputMat.channels()==3)
    {
        DeltaRgb[chl] = (RgbMax[chl] - RgbMin[chl])/255.0;
        AverageRgb[chl] = (RgbMax[chl] + RgbMin[chl])/255.0;
        Lightness[chl] = AverageRgb[chl]/2.0;

        if(Lightness[chl] > 0.5)
        {
            Saturation[chl] = DeltaRgb[chl]/AverageRgb[chl];
        }
        else
        {
            Saturation[chl] = DeltaRgb[chl]/(2-AverageRgb[chl]);
        }

        if(floartRatioConstrast > 0)
        {
            if((floartRatioConstrast + Saturation[chl])>=1)
            {
                alpha[chl] = Saturation[chl];
            }
            else
            {
                alpha[chl] = 1 - floartRatioConstrast;
            }
            alpha[chl] = 1/alpha[chl] -1;
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols;j++)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = mathfun.PixLimit((InputMat.at<Vec3b>(i,j)[chl] - Lightness[chl]*255) * alpha[chl] + InputMat.at<Vec3b>(i,j)[chl]);
                }
            }
        }
        else
        {
            alpha[chl] = floartRatioConstrast;
            for(i=0;i<InputMat.rows;i++)
            {
                for(j=0;j<InputMat.cols;j++)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = mathfun.PixLimit((InputMat.at<Vec3b>(i,j)[chl] - Lightness[chl] * 255) * (alpha[chl] + 1.0) + Lightness[chl]*255);
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


/*Nearest neighbor interpolation*/
unsigned int QtCvFile::NearInterTransform(Mat InputMat, Mat &OutputMat)
{
    int i = 0;
    int j = 0;
    int chl = 0;

    if(InputMat.channels() == 1)
    {
        for(i=0;i<InputMat.rows-1;i++)
        {
            for(j=0;j<InputMat.cols-1;j++)
            {
                if(InputMat.at<uchar>(i,j) == 0 && InputMat.at<uchar>(i,j+1) != 0 && InputMat.at<uchar>(i+1,j) != 0)
                {
                    OutputMat.at<uchar>(i,j) = InputMat.at<uchar>(i,j+1);
                }
                else
                {
                    OutputMat.at<uchar>(i,j) = InputMat.at<uchar>(i,j);
                }
            }
        }
    }
    else if(InputMat.channels() == 3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows-1;i++)
            {
                for(j=0;j<InputMat.cols-1;j++)
                {
                    if(InputMat.at<Vec3b>(i,j)[chl] == 0 && InputMat.at<Vec3b>(i,j+1)[chl] != 0 && InputMat.at<Vec3b>(i+1,j)[chl] != 0)
                    {
                        OutputMat.at<Vec3b>(i,j)[chl] = InputMat.at<Vec3b>(i,j+1)[chl];
                    }
                    else
                    {
                        OutputMat.at<Vec3b>(i,j)[chl] = InputMat.at<Vec3b>(i,j)[chl];
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

unsigned int QtCvFile::fftTransform(Mat InputMat, Mat &OutputMat)
{
    Mat initMat = mathfun.initFFT2(InputMat);
    mathfun.FFT2(initMat, OutputMat);
    mathfun.IFFT2(OutputMat, OutputMat);
    return OK;
}

/*Opencv fft Transform*/
unsigned int QtCvFile::cvDFtLowTransform(Mat InputMat, Mat &OutputMat, int CutOff)
{
    //调整图像加速傅里叶变换
     int M = getOptimalDFTSize(InputMat.rows);
     int N = getOptimalDFTSize(InputMat.cols);
     Mat padded;
     copyMakeBorder(InputMat, padded, 0, M - InputMat.rows, 0, N - InputMat.cols, BORDER_CONSTANT, Scalar::all(0));
     //记录傅里叶变换的实部和虚部
     Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
     Mat complexImg;
     merge(planes, 2, complexImg);
     //进行傅里叶变换
     dft(complexImg, complexImg);
     //获取图像
     Mat mag = complexImg;
     mag = mag(Rect(0, 0, mag.cols & -2, mag.rows & -2));//这里为什么&上-2具体查看opencv文档
     //其实是为了把行和列变成偶数 -2的二进制是11111111.......10 最后一位是0
     //获取中心点坐标
     int cx = mag.cols / 2;
     int cy = mag.rows / 2;
     //调整频域
     Mat tmp;
     Mat q0(mag, Rect(0, 0, cx, cy));
     Mat q1(mag, Rect(cx, 0, cx, cy));
     Mat q2(mag, Rect(0, cy, cx, cy));
     Mat q3(mag, Rect(cx, cy, cx, cy));

     q0.copyTo(tmp);
     q3.copyTo(q0);
     tmp.copyTo(q3);

     q1.copyTo(tmp);
     q2.copyTo(q1);
     tmp.copyTo(q2);
     //处理按公式保留中心部分
     for (int y = 0; y < mag.rows; y++){
         double* data = mag.ptr<double>(y);
         for (int x = 0; x < mag.cols; x++){
             double d = sqrt(pow((y - cy),2) + pow((x - cx),2));
             if (d <= (double)CutOff)
             {
             }
             else
             {
                 data[x] = 0;
             }
         }
     }
     //再调整频域
     q0.copyTo(tmp);
     q3.copyTo(q0);
     tmp.copyTo(q3);
     q1.copyTo(tmp);
     q2.copyTo(q1);
     tmp.copyTo(q2);
     //逆变换
     Mat invDFT;
     idft(mag, invDFT, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
     invDFT.convertTo(OutputMat, CV_8U);
     return OK;
}

/*High pass transform*/
unsigned int QtCvFile::cvDFtHighTransform(Mat InputMat, Mat &OutputMat, int CutOff)
{
    //调整图像加速傅里叶变换
     int M = getOptimalDFTSize(InputMat.rows);
     int N = getOptimalDFTSize(InputMat.cols);
     Mat padded;
     copyMakeBorder(InputMat, padded, 0, M - InputMat.rows, 0, N - InputMat.cols, BORDER_CONSTANT, Scalar::all(0));
     //记录傅里叶变换的实部和虚部
     Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
     Mat complexImg;
     merge(planes, 2, complexImg);
     //进行傅里叶变换
     dft(complexImg, complexImg);
     //获取图像
     Mat mag = complexImg;
     mag = mag(Rect(0, 0, mag.cols & -2, mag.rows & -2));//这里为什么&上-2具体查看opencv文档
     //其实是为了把行和列变成偶数 -2的二进制是11111111.......10 最后一位是0
     //获取中心点坐标
     int cx = mag.cols / 2;
     int cy = mag.rows / 2;
     //调整频域
     Mat tmp;
     Mat q0(mag, Rect(0, 0, cx, cy));
     Mat q1(mag, Rect(cx, 0, cx, cy));
     Mat q2(mag, Rect(0, cy, cx, cy));
     Mat q3(mag, Rect(cx, cy, cx, cy));

     q0.copyTo(tmp);
     q3.copyTo(q0);
     tmp.copyTo(q3);

     q1.copyTo(tmp);
     q2.copyTo(q1);
     tmp.copyTo(q2);
     //处理按公式保留中心部分
     for (int y = 0; y < mag.rows; y++){
         double* data = mag.ptr<double>(y);
         for (int x = 0; x < mag.cols; x++){
             double d = sqrt(pow((y - cy),2) + pow((x - cx),2));
             if (d >= CutOff)
             {
             }
             else
             {
                 data[x] = 0;
             }
         }
     }
     //再调整频域
     q0.copyTo(tmp);
     q3.copyTo(q0);
     tmp.copyTo(q3);
     q1.copyTo(tmp);
     q2.copyTo(q1);
     tmp.copyTo(q2);
     //逆变换
     Mat invDFT;
     idft(mag, invDFT, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
     invDFT.convertTo(OutputMat, CV_8U);
     return OK;
}

unsigned int QtCvFile::cvDFtBandTransform(Mat InputMat, Mat &OutputMat, int CutOff0, int CutOff1)
{
    //调整图像加速傅里叶变换
     int M = getOptimalDFTSize(InputMat.rows);
     int N = getOptimalDFTSize(InputMat.cols);
     Mat padded;
     copyMakeBorder(InputMat, padded, 0, M - InputMat.rows, 0, N - InputMat.cols, BORDER_CONSTANT, Scalar::all(0));
     //记录傅里叶变换的实部和虚部
     Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
     Mat complexImg;
     merge(planes, 2, complexImg);
     //进行傅里叶变换
     dft(complexImg, complexImg);
     //获取图像
     Mat mag = complexImg;
     mag = mag(Rect(0, 0, mag.cols & -2, mag.rows & -2));//这里为什么&上-2具体查看opencv文档
     //其实是为了把行和列变成偶数 -2的二进制是11111111.......10 最后一位是0
     //获取中心点坐标
     int cx = mag.cols / 2;
     int cy = mag.rows / 2;
     //调整频域
     Mat tmp;
     Mat q0(mag, Rect(0, 0, cx, cy));
     Mat q1(mag, Rect(cx, 0, cx, cy));
     Mat q2(mag, Rect(0, cy, cx, cy));
     Mat q3(mag, Rect(cx, cy, cx, cy));

     q0.copyTo(tmp);
     q3.copyTo(q0);
     tmp.copyTo(q3);

     q1.copyTo(tmp);
     q2.copyTo(q1);
     tmp.copyTo(q2);
     //处理按公式保留中心部分
     for (int y = 0; y < mag.rows; y++){
         double* data = mag.ptr<double>(y);
         for (int x = 0; x < mag.cols; x++){
             double d = sqrt(pow((y - cy),2) + pow((x - cx),2));
             if (d >= CutOff0 && d <= CutOff1)
             {
             }
             else
             {
                 data[x] = 0;
             }
         }
     }
     //再调整频域
     q0.copyTo(tmp);
     q3.copyTo(q0);
     tmp.copyTo(q3);
     q1.copyTo(tmp);
     q2.copyTo(q1);
     tmp.copyTo(q2);
     //逆变换
     Mat invDFT;
     idft(mag, invDFT, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
     invDFT.convertTo(OutputMat, CV_8U);
     return OK;
}

unsigned int QtCvFile::ShapenTransform(Mat InputMat, Mat &OutputMat, Mat Filter, unsigned int RatioShapen)
{
    float beta = RatioShapen/100.0;

    Mat matOutTemp1;
    Mat matOutTemp2;
    CreatTempMat(InputMat, matOutTemp1);
    CreatTempMat(InputMat, matOutTemp2);

    matOutTemp1 = InputMat.clone();
    FilterCountSum(InputMat, matOutTemp2, Filter);  /*Count scalar*/
    addWeighted(matOutTemp1, 1, matOutTemp2, beta, 0.0, OutputMat); /*add*/
    return OK;
}

unsigned int QtCvFile::CorrosionTransform(Mat InputMat, Mat &OutputMat, int FilterSize)
{
    int i = 0;
    int j = 0;
    int Filter_i = 0;
    int Filter_j = 0;
    int sum = 0;
    if(InputMat.channels() == 1)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                if(i< FilterSize/2 || (InputMat.rows-1-i)<FilterSize/2 \
                        || j < FilterSize/2 || (InputMat.cols-1-j)<FilterSize/2)
                {
                    OutputMat.at<uchar>(i,j) = 255;
                    continue;
                }
                else
                {
                    for(Filter_i=i-FilterSize/2;Filter_i< i+FilterSize/2;Filter_i++)
                    {
                        for(Filter_j=j-FilterSize/2;Filter_j< j+FilterSize/2;Filter_j++)
                        {
                            sum += InputMat.at<uchar>(Filter_i,Filter_j);

                        }
                    }
                    if(sum > 0)
                    {
                        OutputMat.at<uchar>(i,j) = 255;
                    }
                    sum = 0;
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

unsigned int QtCvFile::ExpandTransform(Mat InputMat, Mat &OutputMat, int FilterSize)
{
    int i = 0;
    int j = 0;
    int Filter_i = 0;
    int Filter_j = 0;
    if(InputMat.channels() == 1)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                if(i< FilterSize/2 || (InputMat.rows-1-i)<FilterSize/2 \
                        || j < FilterSize/2 || (InputMat.cols-1-j)<FilterSize/2)
                {
                    OutputMat.at<uchar>(i,j) = 255;
                    continue;
                }
                else
                {
                    if(InputMat.at<uchar>(i,j) == 0)
                    {
                        for(Filter_i=i-FilterSize/2;Filter_i< i+FilterSize/2;Filter_i++)
                        {
                            for(Filter_j=j-FilterSize/2;Filter_j< j+FilterSize/2;Filter_j++)
                            {
                                OutputMat.at<uchar>(Filter_i,Filter_j) = 0;
                            }
                        }
                    }
                    else
                    {
                        OutputMat.at<uchar>(i,j) = InputMat.at<uchar>(i,j);
                        continue;
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

/*Transform into classical style*/
unsigned int QtCvFile::ClassicalTransform(Mat InputMat, Mat &OutputMat)
{
    int i=0;
    int j = 0;
    uint32 BgrSrc[3];
    uint32 BgrDst[3];

    if(InputMat.channels() == 1)
    {
        OutputMat = InputMat.clone();
    }
    else if(InputMat.channels() == 3)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                BgrSrc[0] = InputMat.at<Vec3b>(i,j)[0];
                BgrSrc[1] = InputMat.at<Vec3b>(i,j)[1];
                BgrSrc[2] = InputMat.at<Vec3b>(i,j)[2];
                mathfun.CoutClassical(BgrSrc,BgrDst);
                OutputMat.at<Vec3b>(i,j)[0] = mathfun.PixLimit(BgrDst[0]);
                OutputMat.at<Vec3b>(i,j)[1] = mathfun.PixLimit(BgrDst[1]);
                OutputMat.at<Vec3b>(i,j)[2] = mathfun.PixLimit(BgrDst[2]);
            }
        }
    }
    else
    {
        return ERROR;
    }
    return OK;
}


/*Transform into Setch Picture*/
unsigned int QtCvFile::SketchTransform(Mat InputMat, Mat &OutputMat, unsigned int SketchThreshold)
{
    int i=0;
    int j = 0;
    int avg = 0;
    if(InputMat.channels() == 1)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            for(j=0;j<InputMat.cols;j++)
            {
                if(i<1 || (InputMat.rows-1-i)<1 || j<1 || (InputMat.cols-1-j)<1)
                {
                     OutputMat.at<uchar>(i,j) = 255;
                     continue;
                }
                else
                {
                    avg = (uint8)((int)(InputMat.at<uchar>(i-1,j-1) + InputMat.at<uchar>(i-1,j) + InputMat.at<uchar>(i-1,j+1) + \
                          InputMat.at<uchar>(i,j-1) + InputMat.at<uchar>(i,j+1) + \
                          InputMat.at<uchar>(i+1,j-1) + InputMat.at<uchar>(i+1,j) + InputMat.at<uchar>(i+1,j+1)) / 8);
                    if((uint8)abs((int)(InputMat.at<uchar>(i,j) - avg)) > (uint8)SketchThreshold)
                    {
                        OutputMat.at<uchar>(i,j) = 0;
                    }
                    else
                    {
                        OutputMat.at<uchar>(i,j) = 255;
                    }
                }
            }
        }
    }
    else if(InputMat.channels() == 3)
    {
        cout<<"transform Photo into Gray Photo first"<<endl;
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/*Transform into oilPaint*/
unsigned int QtCvFile::OilPaintTransform(Mat InputMat, Mat &OutputMat, uint32 FilterSize)
{
    int i=0;
    int j = 0;
    int filter_i = 0;
    int filter_j = 0;
    int chl = 0;
    int FilterRow = 0;
    int FilterCol = 0;
    int maxpix = 0;
    int avg = 0;
    if(InputMat.channels() == 1)
    {
        for(i=0;i<InputMat.rows;i++)
        {
            if(InputMat.rows - 1 - i == 0)
            {
                continue;
            }
            for(j=0;j<InputMat.cols;j++)
            {
                FilterRow = FilterSize;
                FilterCol = FilterSize;
                if(((InputMat.rows - 1 - i) < (int)FilterSize) &&  (InputMat.rows - 1 - i > 0))
                {
                     FilterRow = InputMat.rows - 1 - i;
                }
                else if(((InputMat.cols - 1 - j) < (int)FilterSize) && (InputMat.cols - 1 - j > 0) )
                {
                      FilterCol = InputMat.cols - 1 - j;
                }
                else if(InputMat.cols - 1 - j == 0)
                {
                    continue;
                }
                for(filter_i=i;filter_i<FilterRow+i;filter_i++)
                {
                    for(filter_j=j;filter_j<FilterCol+j;filter_j++)
                    {
                        maxpix = MAXVALUE(maxpix,(int)InputMat.at<uchar>(filter_i,filter_j));
                    }
                }
                avg = maxpix;
                for(filter_i=i;filter_i<FilterRow+i;filter_i++)
                {
                    for(filter_j=j;filter_j<FilterCol+j;filter_j++)
                    {
                        OutputMat.at<uchar>(filter_i,filter_j) = avg;
                    }
                }
                j = j + FilterCol -1;
                maxpix = 0;
            }
            i = i + FilterRow -1;
        }
    }
    else if(InputMat.channels() == 3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                if(InputMat.rows - 1 - i == 0)
                {
                    continue;
                }
                for(j=0;j<InputMat.cols;j++)
                {
                    FilterRow = FilterSize;
                    FilterCol = FilterSize;
                    if(((InputMat.rows - 1 - i) < (int)FilterSize) &&  (InputMat.rows - 1 - i > 0))
                    {
                         FilterRow = InputMat.rows - 1 - i;
                    }
                    else if(((InputMat.cols - 1 - j) < (int)FilterSize) && (InputMat.cols - 1 - j > 0) )
                    {
                          FilterCol = InputMat.cols - 1 - j;
                    }
                    else if(InputMat.cols - 1 - j == 0)
                    {
                        continue;
                    }
                    for(filter_i=i;filter_i<FilterRow+i;filter_i++)
                    {
                        for(filter_j=j;filter_j<FilterCol+j;filter_j++)
                        {
                            maxpix = MAXVALUE(maxpix, (int)InputMat.at<Vec3b>(filter_i,filter_j)[chl]);
                        }
                    }
                    avg = maxpix;
                    for(filter_i=i;filter_i<FilterRow+i;filter_i++)
                    {
                        for(filter_j=j;filter_j<FilterCol+j;filter_j++)
                        {
                            OutputMat.at<Vec3b>(filter_i,filter_j)[chl] = avg;
                        }
                    }
                    j = j + FilterCol -1;
                    maxpix = 0;
                }
                i = i + FilterRow -1;
            }
        }
    }
    else
    {
        return ERROR;
    }
    return OK;
}


/********************************************************************************************************************/
/*Average method*/
uint32 QtCvFile::FilterCountAverage(Mat InputMat, Mat& OutputMat, uint32 add[3], Mat Filter)
{
    int i=0;
    int j=0;
    int chl = 0;
    int key_cols = 0;
    int key_rows = 0;
    int filter_i = 0;
    int filter_j = 0;
    int sum = 0;
    if(Filter.cols != Filter.rows || (Filter.cols %2) ==0 || (Filter.rows %2) == 0)
    {
        return ERROR;
    }
    if(InputMat.channels() == 1)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                if(i<Filter.rows/2 || (InputMat.rows-1-i)<Filter.rows/2)
                {
                    OutputMat.at<uchar>(i,j) = InputMat.at<uchar>(i,j);
                    continue;
                }
                else
                {
                    for(j=0;j<InputMat.cols;j++)
                    {

                        if(j<Filter.cols/2 || (InputMat.cols-1-j)<Filter.cols/2)
                        {
                            OutputMat.at<uchar>(i,j) = InputMat.at<uchar>(i,j);
                            continue;
                        }
                        else
                        {
                            for(key_rows=i-Filter.rows/2,filter_i = 0;key_rows<=i+Filter.rows/2;key_rows++,filter_i++)
                            {
                                 for(key_cols=j-Filter.cols/2,filter_j=0;key_cols<=j+Filter.cols/2;key_cols++,filter_j++)
                                 {
                                     sum += (InputMat.at<uchar>(key_rows,key_cols)* Filter.at<uchar>(filter_i,filter_j));
                                 }

                            }
                            sum = sum / add[chl];
                            if(sum< 0)
                            {
                                 sum = 0;
                                 OutputMat.at<uchar>(i,j) = sum;
                            }
                            else if(sum > 255)
                            {

                                sum = 255;
                                OutputMat.at<uchar>(i,j) = sum;
                                sum = 0;
                            }
                            else
                            {
                                OutputMat.at<uchar>(i,j) = sum;
                                sum = 0;
                            }
                        }
                    }
                }
            }
        add[chl] = 0;
        }
    }
    else if(InputMat.channels() == 3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                if(i<Filter.rows/2 || (InputMat.rows-1-i)<Filter.rows/2)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = InputMat.at<Vec3b>(i,j)[chl];
                    continue;
                }
                else
                {
                    for(j=0;j<InputMat.cols;j++)
                    {

                        if(j<Filter.cols/2 || (InputMat.cols-1-j)<Filter.cols/2)
                        {
                            OutputMat.at<Vec3b>(i,j)[chl] = InputMat.at<Vec3b>(i,j)[chl];
                            continue;
                        }
                        else
                        {
                            for(key_rows=i-Filter.rows/2,filter_i = 0;key_rows<=i+Filter.rows/2;key_rows++,filter_i++)
                            {
                                 for(key_cols=j-Filter.cols/2,filter_j=0;key_cols<=j+Filter.cols/2;key_cols++,filter_j++)
                                 {
                                     sum += (InputMat.at<Vec3b>(key_rows,key_cols)[chl] * Filter.at<Vec3b>(filter_i,filter_j)[chl]);
                                 }

                            }
                            sum = sum / add[chl];
                            if(sum< 0)
                            {
                                 sum = 0;
                                 OutputMat.at<Vec3b>(i,j)[chl] = sum;
                            }
                            else if(sum > 255)
                            {

                                sum = 255;
                                OutputMat.at<Vec3b>(i,j)[chl] = sum;
                                sum = 0;
                            }
                            else
                            {
                                OutputMat.at<Vec3b>(i,j)[chl] = sum;
                                sum = 0;
                            }
                        }
                    }
                }
            }
        add[chl] = 0;
        }
    }
    else
    {
        return ERROR;
    }

    return OK;
}

/*Sum method*/
uint32 QtCvFile::FilterCountSum(Mat InputMat, Mat& OutputMat, Mat Filter)
{
    int i=0;
    int j=0;
    int chl = 0;
    int key_cols = 0;
    int key_rows = 0;
    int filter_i = 0;
    int filter_j = 0;
    int sum = 0;
    if(Filter.cols != Filter.rows || (Filter.cols %2) ==0 || (Filter.rows %2) == 0)
    {
        return ERROR;
    }
    if(InputMat.channels() == 1)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                if(i<Filter.rows/2 || (InputMat.rows-1-i)<Filter.rows/2)
                {
                    OutputMat.at<uchar>(i,j) = 255;
                    continue;
                }
                else
                {
                    for(j=0;j<InputMat.cols;j++)
                    {

                        if(j<Filter.cols/2 || (InputMat.cols-1-j)<Filter.cols/2)
                        {
                            OutputMat.at<uchar>(i,j) = 255;
                            continue;
                        }
                        else
                        {
                            for(key_rows=i-Filter.rows/2,filter_i = 0;key_rows<=i+Filter.rows/2;key_rows++,filter_i++)
                            {
                                 for(key_cols=j-Filter.cols/2,filter_j=0;key_cols<=j+Filter.cols/2;key_cols++,filter_j++)
                                 {
                                     sum += (int)(InputMat.at<uchar>(key_rows,key_cols) * Filter.at<float>(filter_i,filter_j));
                                 }

                            }
                            OutputMat.at<uchar>(i,j) = mathfun.PixLimit(abs(sum));
                            sum = 0;
                        }
                    }
                }
            }
        }
    }
    else if(InputMat.channels() == 3)
    {
        for(chl=0;chl<InputMat.channels();chl++)
        {
            for(i=0;i<InputMat.rows;i++)
            {
                if(i<Filter.rows/2 || (InputMat.rows-1-i)<Filter.rows/2)
                {
                    OutputMat.at<Vec3b>(i,j)[chl] = 255;
                    continue;
                }
                else
                {
                    for(j=0;j<InputMat.cols;j++)
                    {

                        if(j<Filter.cols/2 || (InputMat.cols-1-j)<Filter.cols/2)
                        {
                            OutputMat.at<Vec3b>(i,j)[chl] = 255;
                            continue;
                        }
                        else
                        {
                            for(key_rows=i-Filter.rows/2,filter_i = 0;key_rows<=i+Filter.rows/2;key_rows++,filter_i++)
                            {
                                 for(key_cols=j-Filter.cols/2,filter_j=0;key_cols<=j+Filter.cols/2;key_cols++,filter_j++)
                                 {
                                     sum += (int)(InputMat.at<Vec3b>(key_rows,key_cols)[chl] * Filter.at<Vec3f>(filter_i,filter_j)[chl]);
                                 }
                            }
                            OutputMat.at<Vec3b>(i,j)[chl] = mathfun.PixLimit(abs(sum));
                            sum = 0;
                        }
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
