#include <iostream>

#include "stdfile.h"
#include "lenet.h"
#include "mathlib.h"


using namespace std;

LeNet::LeNet()
{

}

LeNet::~LeNet()
{
    cout<<"release this class"<<endl;
}

/*LeNet Mat Init*/
int LeNet::LeNetMatInit()
{
    int i;
    for(i=0;i<LNetCon1Chl;i++)
    {
        LNetCon1[i] = Mat::zeros(LNetCon1Size, LNetCon1Size, CV_32FC1);
        LNetCon1Sum[i] =  Mat::zeros(LNetCon1Size, LNetCon1Size, CV_32FC1);
        cv::randu(LNetCon1[i], cv::Scalar::all(-1.), cv::Scalar::all(1.));
    }
    for(i=0;i<LNetCon2Chl;i++)
    {
        LNetCon2[i] = Mat::zeros(LNetCon2Size, LNetCon2Size, CV_32FC1);
        LNetCon2Sum[i] =  Mat::zeros(LNetCon2Size, LNetCon2Size, CV_32FC1);
        cv::randu(LNetCon2[i], cv::Scalar::all(-1.), cv::Scalar::all(1.));
    }
    return OK;
}

/*LeNet Data Init*/
int LeNet::LeNetDataInit()
{
    LNetTrainLable = new int[LNetTrainNum];
    readLable(sLNetLableRoot, LNetTrainLable, LNetTrainNum); /*Get Lable from lable.txt*/

    LNetReadDataLock = false;
    return OK;
}

/*LeNet Init*/
int LeNet::LeNetInit()
{
    LeNetMatInit();
    LeNetDataInit();
    return OK;
}

/*LeNet ForWard*/
float LeNet::LeNetForWard(Mat matIn, Mat matReal, bool& isTrue, int& expectValue)
{
    float crossEntropy = 0.0;
    return crossEntropy;
}

/*LeNet Train*/
int LeNet::LeNetTrain()
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

    for(i=0;i<LNetTrainNum;i++)
    {
        /*Get Lable*/
        lable = *(LNetTrainLable + i);
        MatRealTransform(lable, matReal);

        /*Get Image*/
        string ImageName = sLNetImageRoot + to_string((int)i) + ".png";
        matIn = imread(ImageName);

        /*ForwardPgt*/
        tmp =LeNetForWard(matIn, matReal, isTrue, expectValue);

        if(isTrue)
        {
            count +=1;
            isTrue = false;
        }

        /*adjust weight*/
        if(i % LNetBatchSize == 0 && i != 0)
        {
             //WeightBiasAdj();

        }
        if(i % 1000 == 0 && i != 0)
        {
            LNetCrossEntropy = tmp;
            TrueRate = (float)count / 1000;
            count = 0;
            LNetLearnRate = 1 - TrueRate;
            cout<<"train times"<<i<<endl;
            cout<<"True Rate is :"<<TrueRate<<endl;
        }
    }

    return OK;
}

/*LeNetTest Train*/
int LeNet::LeNetTest(int TestNum, Mat &matIn, int &expectValue, bool &isTrue)
{
    /*Read data*/
    if(!LNetReadDataLock)
    {
        //ReadBpTrainValue(sSaveRoot, matWeightInHd, matBiasInHd, matWeightHdOut, matBiasHdOut);
        LNetReadDataLock = true;
    }

    int lable;
    Mat matReal;

    /*Get Lable*/
    lable = *(LNetTrainLable + TestNum);
    MatRealTransform(lable, matReal);

    /*Get Image*/
    string ImageName = sLNetImageRoot + to_string(int(TestNum)) + ".png";
    matIn = imread(ImageName);

    /*ForwardPgt*/
    LeNetForWard(matIn, matReal, isTrue, expectValue);
    cout<<"isTrue"<<isTrue<<endl;

    return OK;
}
