#ifndef QTCVFILE_H
#define QTCVFILE_H
#include <QWidget>

#include "stddatatype.h"
#include "mathfun.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class QtCvFile : public QWidget
{    
    Q_OBJECT

    public:
        QtCvFile();  //construction function

        uint32 OpenImageFile(Mat& mat);  //Open image File
        uint32 SaveImageFile(Mat mat);  //Save image File
        uint32 cvMat2QImage(Mat mat, QImage& Qimg); //convert mat to QImage
        uint32 QImage2cvMat(QImage Qimg, Mat& mat); //convert image to Mat
        uint32 SplitBGRToMat(Mat mat, Mat& BlueMat, Mat& GreenMat, Mat& RedMat); //split 3 channel into 1 channel
        uint32 MergeBRGtoMat(Mat BlueMat, Mat GreenMat, Mat RedMat, Mat& mat); //merge 3 single-channel into 3 channel image
        uint32 CompareMat(Mat matA, Mat matB, int& flag);
        uint32 CreatTempMat(Mat InputMat, Mat& OutputMat);
        uint32 CreatTempFilter(Mat InputMat, uint8 FilterSize, Mat &Filter);
        /*Filter*/
        uint32 AverageFilter(uint8 FilterSize, uint32 sum[3], Mat& Filter);
        uint32 GaussianFilter(uint8 FilterSize, uint32 sum[3], float sigma, Mat &Filter); /*average Filter*/
        uint32 LaplaceFilter(Mat &Filter);/*laplace Filter*/
        uint32 CreatFloatFilter(Mat InputMat, unsigned int FilterSize, Mat &Filter);
        uint32 CountHistogram(Mat InputMat,int distribution[3][255]);
        uint32 HistogramTransform(Mat InputMat, int distribution[3][255], Mat& OutputMat);

        uint32 BinaryTransform(Mat InputMat, Mat& OutputMat, uint32 BinaryThrehold);
        uint32 GrayscalTransform(Mat InputMat, Mat& OutputMat);
        uint32 DataTypeTransform(Mat InputMat, Mat& OutputMat);
        uint32 MinorYTransform(Mat InputMat, Mat& OutputMat);
        uint32 MinorXTransform(Mat InputMat, Mat& OutputMat);
        uint32 RatationTransform(Mat InputMat, Mat& OutputMat, int angle);
        uint32 BrightTransform(Mat InputMat, Mat& OutputMat, uint32 RatioBrightness);
        uint32 ConstrastTransform(Mat InputMat, Mat& OutputMat, uint32 RatioConstrast);
        uint32 SaturationTransform(Mat InputMat, Mat& OutputMat, uint32 RatioSaturation);
        uint32 NearInterTransform(Mat InputMat, Mat& OutputMat);
        uint32 fftTransform(Mat InputMat, Mat& OutputMat);
        uint32 cvDFtLowTransform(Mat InputMat, Mat& OutputMat, int CutOff);
        uint32 cvDFtHighTransform(Mat InputMat, Mat& OutputMat, int CutOff);
        uint32 cvDFtBandTransform(Mat InputMat, Mat& OutputMat, int CutOff0, int CutOff1);

        uint32 ShapenTransform(Mat InputMat, Mat &OutputMat, Mat Filter, unsigned int RatioShapen);
        uint32 CorrosionTransform(Mat InputMat, Mat &OutputMat, int FilterSize);
        uint32 ExpandTransform(Mat InputMat, Mat &OutputMat, int FilterSize);
        uint32 ClassicalTransform(Mat InputMat, Mat &OutputMat);
        uint32 SketchTransform(Mat InputMat, Mat &OutputMat, unsigned int SketchThreshold);
        uint32 OilPaintTransform(Mat InputMat, Mat &OutputMat, uint32 FilterSize);

        /*Filter */
        uint32 FilterCountAverage(Mat InputMat, Mat& OutputMat, uint32 add[3], Mat Filter); /**/
        uint32 FilterCountSum(Mat InputMat, Mat& OutputMat, Mat Filter);

    private:
        MathFun mathfun;
        Mat BlueMat;
        Mat GreenMat;
        Mat RedMat;

    protected:


};

#endif // QTCVFILE_H
