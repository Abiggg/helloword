#include <iostream>
#include <string>
#include <unistd.h>
#include <QtCore/QtCore>
#include <QKeyEvent>

#include "bpnetwork.h"
#include "mathlib.h"
#include "stdfile.h"

using namespace std;
using namespace cv;

BpNetwork::BpNetwork()
{

}

BpNetwork::~BpNetwork()
{
   delete TrainLable;
}

unsigned int BpNetwork::MatToLine(Mat matIn, Mat &matOut)
{
    int i;
    int j;
    int count = 0;
    for(i=0;i<matIn.rows;i++)
    {
        for(j=0;j<matIn.cols;j++)
        {
            count +=1;
            if(count > inNum)
            {
                return OK;
            }
            matOut.at<float>(0,i * matIn.cols + j ) = (float)matIn.at<uchar>(i,j)/1.0;
        }
    }
    return OK;
}

/*Init gloal private Mat*/
unsigned int BpNetwork::MatInit()
{
    matWeightInHd = Mat::zeros(inNum, hdNum, CV_32FC1);
    matWeightInHdSum =  Mat::zeros(inNum, hdNum, CV_32FC1);
    cv::randu(matWeightInHd, cv::Scalar::all(-1.), cv::Scalar::all(1.));

    matBiasInHd = Mat::ones(1, hdNum, CV_32FC1) / 10.0;
    matBiasInHdSum = Mat::zeros(1, hdNum, CV_32FC1);
    //cv::randu(matBiasInHd, cv::Scalar::all(-1.), cv::Scalar::all(1.));

    matWeightHdOut = Mat::zeros(hdNum, OutNum, CV_32FC1);
    matWeightHdOutSum = Mat::zeros(hdNum, OutNum, CV_32FC1);
    cv::randu(matWeightHdOut, cv::Scalar::all(-1.), cv::Scalar::all(1.));

    matBiasHdOut = Mat::ones(1, OutNum, CV_32FC1) / 10.0;
    matBiasHdOutSum = Mat::zeros(1, OutNum, CV_32FC1);
    //cv::randu(matBiasHdOut, cv::Scalar::all(-1.), cv::Scalar::all(1.));

    return OK;
}


/*Init Lable value*/
unsigned int BpNetwork::DataInit()
{
    TrainLable = new int[TrainNum];
    readLable(sLableRoot, TrainLable, TrainNum); /*Get Lable from lable.txt*/

    BpReadDataLock = false;
    return OK;
}

/*BpNetWork Init*/
unsigned int BpNetwork::BpNetWortInit()
{
    MatInit();
    DataInit();
    return OK;
}

/*Forward Pro*/
float BpNetwork::BpForwardPgt(Mat matIn, Mat matReal, bool& isTrue, int& expectValue)
{
    float tmpCrossEntropy;
    /*
     * matInLine->(w1,b1)->matInHd->(sigmod)->matInHd->(w2,b2)->matHdOut->(sigmod)->matHdOut->(softmax)->matOut-> CrossEntropy
     *  [1][5]    [5][4]    [1][4]             [1][4]   [4][2]   [2][1]             [2][1]               [2][1]
     *        matDiffSoftmax
     */
    Mat matInLine = Mat::zeros(1, inNum, CV_32FC1); /*matIn*/
    Mat matInHd = Mat::zeros(1, hdNum, CV_32FC1);
    Mat matHdOut = Mat::zeros(1, OutNum, CV_32FC1);
    Mat matOut = Mat::zeros(1, OutNum, CV_32FC1);

    Mat matDiffSigmoidIn = Mat::zeros(1, hdNum, CV_32FC1);
    Mat matDiffSigmoidOut = Mat::zeros(1, OutNum, CV_32FC1);
    Mat matDiffSoftmax = Mat::zeros(1, OutNum, CV_32FC1);
    Mat matWeightHdOut_T;

    Mat matWeightInHdTemp =  Mat::zeros(inNum, hdNum, CV_32FC1);
    Mat matBiasInHdTemp = Mat::zeros(1, hdNum, CV_32FC1);
    Mat matWeightHdOutTemp = Mat::zeros(hdNum, OutNum, CV_32FC1);
    Mat matBiasHdOutTemp = Mat::zeros(1, OutNum, CV_32FC1);

    float DiffCrossEntropy = 0;
    int pos = 0;

    /*reshape photo into one line--testok*/
    MatToLine(matIn, matInLine);

    /*first layer-->in to hd*/
    matInHd = matInLine * matWeightInHd + matBiasInHd;
    MatSigmoid(matInHd, matInHd, matDiffSigmoidIn, 200);

    //MatRelu(matInHd, matInHd, matDiffSigmoidIn);

    /*second layer --> hd to out*/
    matHdOut = matInHd * matWeightHdOut + matBiasHdOut;
    MatSigmoid(matHdOut, matHdOut, matDiffSigmoidOut, 5);
    //MatRelu(matHdOut, matHdOut, matDiffSigmoidOut);

    /*softMax*/
    MatSoftmax(matHdOut, matOut);

    /*Loss Function --> CrossEntropy*/
    tmpCrossEntropy = MatCrossEntropy(matOut, matReal, DiffCrossEntropy, pos);
    /*get the diff of softmax*/
    MatDiffSoftmax(matOut, pos, matDiffSoftmax);

    /*judge if is true*/
    expectValue = MatMaxfloat(matOut);

    if(MatMaxInt(matReal) == MatMaxfloat(matOut))
    {
        isTrue = true;
    }
    else
    {
        isTrue = false;
    }

    matBiasHdOutTemp = MatPlus(matDiffSoftmax * DiffCrossEntropy, matDiffSigmoidOut);
    //matBiasHdOutTemp = matDiffSoftmax * DiffCrossEntropy;
    matWeightHdOutTemp = MatReverse(matInHd, matBiasHdOutTemp);

    transpose(matWeightHdOut, matWeightHdOut_T);
    matBiasInHdTemp = MatPlus(matBiasHdOutTemp * matWeightHdOut_T,  matDiffSigmoidIn);
    matWeightInHdTemp = MatReverse(matInLine, matBiasInHdTemp);

    matWeightInHdSum += matWeightInHdTemp;
    matBiasInHdSum += matBiasInHdTemp;
    matWeightHdOutSum += matWeightHdOutTemp;
    matBiasHdOutSum += matBiasHdOutTemp;

    return tmpCrossEntropy;
}

/*Weight and Bias adjusment*/
unsigned int BpNetwork::WeightBiasAdj()
{
    matWeightInHd = matWeightInHd - matWeightInHdSum / BatchSize * LearingRate -0.0001*matWeightInHd;
    matBiasInHd = matBiasInHd - matBiasInHdSum / BatchSize  * LearingRate -0.0001 * matBiasInHd;
    matWeightHdOut = matWeightHdOut - matWeightHdOutSum / BatchSize  * LearingRate -0.0001 * matWeightHdOut;
    matBiasHdOut = matBiasHdOut - matBiasHdOutSum / BatchSize  * LearingRate -0.0001 * matBiasHdOut;

    matWeightInHdSum =  Mat::zeros(inNum, hdNum, CV_32FC1);
    matBiasInHdSum = Mat::zeros(1, hdNum, CV_32FC1);
    matWeightHdOutSum = Mat::zeros(hdNum, OutNum, CV_32FC1);
    matBiasHdOutSum = Mat::zeros(1, OutNum, CV_32FC1);

    return OK;
}

/*Bp NetWork Train*/
unsigned int BpNetwork::BpNetWorkTrain()
{
    int lable;
    int i;
    Mat matIn;
    Mat matReal;
    float tmp;
    bool isTrue = false ;
    int count = 0;
    float TrueRate;   /*the rate of success*/
    int expectValue;

    for(i=0;i<TrainNum;i++)
    {
        /*Get Lable*/
        lable = *(TrainLable + i);
        MatRealTransform(lable, matReal);

        /*Get Image*/
        string ImageName = sImageRoot + to_string((int)i) + ".png";
        matIn = imread(ImageName);

        /*ForwardPgt*/
        tmp =BpForwardPgt(matIn, matReal, isTrue, expectValue);

        if(isTrue)
        {
            count +=1;
            isTrue = false;
        }

        /*adjust weight*/
        if(i % BatchSize == 0 && i != 0)
        {
             WeightBiasAdj();

        }
        if(i % 1000 == 0 && i != 0)
        {
            CrossEntropy = tmp;
            TrueRate = (float)count / 1000;
            count = 0;
            LearingRate = 1 - TrueRate;
            cout<<"train times"<<i<<endl;
            cout<<"True Rate is :"<<TrueRate<<endl;
        }
    }

    return OK;
}

/*Bp NetWork Test*/
unsigned int BpNetwork::BpNetWorkTest(int TestNum, Mat& matIn, int& expectValue, bool& isTrue)
{
    /*Read data*/
    if(!BpReadDataLock)
    {
        ReadBpTrainValue(sSaveRoot, matWeightInHd, matBiasInHd, matWeightHdOut, matBiasHdOut);
        BpReadDataLock = true;
    }

    int lable;
    Mat matReal;

    /*Get Lable*/
    lable = *(TrainLable + TestNum);
    MatRealTransform(lable, matReal);

    /*Get Image*/
    string ImageName = sImageRoot + to_string(int(TestNum)) + ".png";
    matIn = imread(ImageName);

    /*ForwardPgt*/
    BpForwardPgt(matIn, matReal, isTrue, expectValue);
    cout<<"isTrue"<<isTrue<<endl;

    return OK;
}

unsigned int BpNetwork::BpNetWorkSaveData()
{
    /*Save Data*/
    SaveBpTrainValue(sSaveRoot, matWeightInHd, matBiasInHd, matWeightHdOut, matBiasHdOut);
    sleep(0.5);
    BpReadDataLock = false;
    cout<<"save data"<<endl;
    return OK;
}


