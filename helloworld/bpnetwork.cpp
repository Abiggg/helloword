#include <iostream>
#include <string>

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
    for(i=0;i<matIn.rows;i++)
    {
        for(j=0;j<matIn.cols;j++)
        {
            matOut.at<float>(0,i * matIn.cols + j ) = (float)matIn.at<uchar>(i,j)*1.0;
        }
    }
    return OK;
}

/*Init gloal private Mat*/
unsigned int BpNetwork::MatInit()
{
    matWeightInHd = Mat::zeros(inNum, hdNum, CV_32FC1);
    matWeightInHdTemp =  Mat::zeros(inNum, hdNum, CV_32FC1);
    cv::randu(matWeightInHd, cv::Scalar::all(-1.), cv::Scalar::all(1.));

    matBiasInHd = Mat::zeros(1, hdNum, CV_32FC1);
    matBiasInHdTemp = Mat::zeros(1, hdNum, CV_32FC1);
    cv::randu(matBiasInHd, cv::Scalar::all(-1.), cv::Scalar::all(1.));


    matWeightHdOut = Mat::zeros(hdNum, OutNum, CV_32FC1);
    matWeightHdOutTemp = Mat::zeros(hdNum, OutNum, CV_32FC1);
    cv::randu(matWeightHdOut, cv::Scalar::all(-1.), cv::Scalar::all(1.));


    matBiasHdOut = Mat::zeros(1, OutNum, CV_32FC1);
    matBiasHdOutTemp = Mat::zeros(1, OutNum, CV_32FC1);
    cv::randu(matBiasHdOut, cv::Scalar::all(-1.), cv::Scalar::all(1.));

    return OK;
}


/*Init Lable value*/
unsigned int BpNetwork::DataInit()
{
    TrainLable = new int[TrainNum];
    readLable(sLableRoot, TrainLable, TrainNum); /*Get Lable from lable.txt*/
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
float BpNetwork::BpForwardPgt(Mat matIn, Mat matReal, bool& isTrue)
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
    float matDiffCrossEntropy = 0;
    int pos = 0;

    /*reshape photo into one line*/
    MatToLine(matIn, matInLine);

    /*first layer-->in to hd*/
    matInHd = matInLine * matWeightInHd + matBiasInHd;
    MatSigmoid(matInHd, matInHd, matDiffSigmoidIn);

    /*second layer --> hd to out*/
    matHdOut = matInHd * matWeightHdOut + matBiasHdOut;
    MatSigmoid(matHdOut, matHdOut, matDiffSigmoidOut);

    /*softMax*/
    MatSoftmax(matHdOut, matOut);

    /*Loss Function --> CrossEntropy*/
    tmpCrossEntropy = MatCrossEntropy(matOut, matReal, matDiffCrossEntropy, pos);

    /*get the diff of softmax*/
    MatDiffSoftmax(matOut, pos, matDiffSoftmax);

    /*judge if is true*/
    if(MatMaxInt(matReal) == MatMaxfloat(matOut))
    {
        isTrue = true;
    }

    matBiasHdOutTemp += MatPlus(matDiffSoftmax * matDiffCrossEntropy, matDiffSigmoidOut);
    matWeightHdOutTemp += MatReverse(matInHd, matBiasHdOutTemp);
    matBiasInHdTemp += MatPlus(MatCombine(matWeightHdOut), matDiffSigmoidIn);
    matWeightInHdTemp += MatReverse(matInLine, matBiasInHdTemp);

    return -tmpCrossEntropy;
}

/*Weight and Bias adjusment*/
unsigned int BpNetwork::WeightBiasAdj()
{
    matWeightInHd = matWeightInHd - matWeightInHdTemp / BatchSize;
    matBiasInHd = matBiasInHd - matBiasInHdTemp / BatchSize;
    matWeightHdOut = matWeightHdOut - matWeightHdOutTemp / BatchSize;
    matBiasHdOut = matBiasHdOut - matBiasHdOutTemp / BatchSize;

    matWeightInHdTemp =  Mat::zeros(inNum, hdNum, CV_32FC1);
    matBiasInHdTemp = Mat::zeros(1, hdNum, CV_32FC1);
    matWeightHdOutTemp = Mat::zeros(hdNum, OutNum, CV_32FC1);
    matBiasHdOutTemp = Mat::zeros(1, OutNum, CV_32FC1);

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
    for(i=0;i<TrainNum;i++)
    {
        /*Get Lable*/
        lable = *(TrainLable + i);
        lable = *(TrainLable + i);
        MatRealTransform(lable, matReal);

        /*Get Image*/
        stringstream strStream;
        strStream << i;
        string ImageName = sImageRoot + strStream.str() + ".png";
        matIn = imread(ImageName);
        /*ForwardPgt*/
        tmp =BpForwardPgt(matIn, matReal, isTrue);

        if(isTrue)
        {
            count +=1;
            isTrue = false;
        }

        /*adjust weight*/
        if(i % BatchSize == 0 && i != 0)
        {
             WeightBiasAdj();
             CrossEntropy = tmp;
             TrueRate = (float)count / BatchSize;
             count = 0;
             cout<<"CrossEntropy :"<<CrossEntropy<<endl;
             cout<<"True Rate is :"<<TrueRate<<endl;
        }
    }

    return OK;
}

/*Bp NetWork Test*/
unsigned int BpNetwork::BpNetWorkTest()
{
    return OK;
}


