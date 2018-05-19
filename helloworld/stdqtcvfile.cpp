#include "stdqtcvfile.h"

#include <iostream>
#

#include "QMenu"
#include "QMenuBar"
#include "QAction"
#include "QMessageBox"
#include "QFileDialog"
#include "QDebug"


using namespace cv;
using namespace std;

QtCvFile::QtCvFile()
{

}

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
}
uint32 QtCvFile::QImage2cvMat(QImage Qimg, Mat& mat)
{
    qDebug() << Qimg.format();
    cout<<Qimg.format() <<endl;
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
//split image into B G R
uint32 QtCvFile::SplitBGRToMat(Mat mat, Mat &BlueMat, Mat &GreenMat, Mat &RedMat)
{
     vector<Mat> channels;
    split(mat,channels);
    BlueMat = channels.at(0);
    GreenMat = channels.at(1);
    RedMat = channels.at(2);
    return OK;
}
//Merge image into single Mat
uint32 QtCvFile::MergeBRGtoMat(Mat BlueMat, Mat GreenMat, Mat RedMat, Mat& mat)
{
    vector<Mat> channels;
    channels.push_back(BlueMat);
    channels.push_back(GreenMat);
    channels.push_back(RedMat);
    merge(channels,mat);
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
                    Filter.at<int>(i,j)[chl] = -8;
                }
                else
                {
                    Filter.at<int>(i,j)[chl] = 1;
                }
            }
        }
    }
    return OK;
}


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
    return OK;
}



