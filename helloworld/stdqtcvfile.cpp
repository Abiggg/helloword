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

uint32 QtCvFile::OpenImageFile(Mat *image)
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
    *image = imread(fileName);//读入一站图片 暂时读入桌面上的一个文件
    cvtColor(*image,*image,CV_BGR2RGB);//opencv读取图片按照BGR方式读取，为了正常显示，所以将BGR转为RGB
    return OK;
    }
    else
    {
     fd->close();
     return ERROR;
    }
}

uint32 QtCvFile::SaveImageFile(Mat image)
{
    QString QfileName;
    QfileName = QFileDialog::getSaveFileName(this,
                                             tr("Save Image"),
                                             "",
                                             "Images (*.png *.bmp *.jpg *.jpeg)"); //选择路径
    string fileAsSave = QfileName.toStdString();
    imwrite(fileAsSave,image);
    return OK;
}


uint32 QtCvFile::cvMat2QImage(const Mat& mat, QImage& image)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        image = QImage(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
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
        image = QImage(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        image = image.rgbSwapped();
        return OK;
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        image = QImage(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return OK;
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return ERROR;
    }
}
Mat QtCvFile::QImage2cvMat(QImage image)
{
    Mat mat;
    qDebug() << image.format();
    if(image.format() == QImage::Format_ARGB32_Premultiplied)
    {
        mat = Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
    }
    else if (image.format() == QImage::Format_RGB888)
    {
        mat = Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
    }
    else if (image.format() == QImage::Format_Indexed8)
    {
        mat = Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
    }
    else
    {
        cout<<"unknow type of Qimage"<<endl;
    }
    return mat;
}
