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
    for(i=0;i<CON1CHL;i++)
    {
        matLNetCon1[i] = Mat::zeros(LNetCon1Size, LNetCon1Size, CV_32FC1);
        matLNetBase1[i] =Mat::zeros(12, 12, CV_32FC1);
        //matLNetCon1Sum[i] =  Mat::zeros(LNetCon1Size, LNetCon1Size, CV_32FC1);
        cv::randu(matLNetCon1[i], cv::Scalar::all(-1.), cv::Scalar::all(1.));
        cv::randu(matLNetBase1[i], cv::Scalar::all(-1.), cv::Scalar::all(1.));
    }
    for(i=0;i<CON2CHL;i++)
    {
        matLNetBase2[i] =Mat::zeros(4, 4, CV_32FC1);
        matLNetCon2[i] = Mat::zeros(LNetCon2Size, LNetCon2Size, CV_32FC1);
        //matLNetCon2Sum[i] =  Mat::zeros(LNetCon2Size, LNetCon2Size, CV_32FC1);
        cv::randu(matLNetCon2[i], cv::Scalar::all(-1.), cv::Scalar::all(1.));
        cv::randu(matLNetBase2[i], cv::Scalar::all(-1.), cv::Scalar::all(1.));
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

Mat LeNet::MattoFloat(Mat matIn)
{
    int i;
    int j;
    Mat TmpMat = Mat::zeros(matIn.rows, matIn.cols, CV_32FC1);
    for(i=0;i<matIn.rows;i++)
    {
        for(j=0;j<matIn.cols;j++)
        {
            TmpMat.at<float>(i,j) = (float)matIn.at<uchar>(i,j) / 125.0;
        }
    }
    return TmpMat;
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
    int i;
    float crossEntropy = 0.0;
    int Strides = 1;
    int PoolStrides = 2;
    int isPadding = 0;

    /*MatIn Transform*/
    Mat tmpMatIn[1];
    tmpMatIn[0] = MattoFloat(matIn);
    /*Mat tmpMatCon1 Init*/
    Mat tmpMatCon1[CON1CHL];
    for(i=0;i<CON1CHL;i++)
    {
        tmpMatCon1[i] = Mat::zeros((matIn.rows/Strides-LNetCon1Size + 1), (matIn.cols/Strides - LNetCon1Size + 1), CV_32FC1);
    }

    /*Mat tmpMatPool1 Init*/
    Mat tmpMatPool1[CON1CHL];
    for(i=0;i<CON1CHL;i++)
    {
        tmpMatPool1[i] = Mat::zeros((tmpMatCon1[0].rows/PoolStrides), (tmpMatCon1[0].cols/PoolStrides), CV_32FC1);
    }

    Mat tmpMatcon2[CON2CHL];
    for(i=0;i<CON2CHL;i++)
    {
        tmpMatcon2[i] = Mat::zeros((tmpMatPool1[0].rows/Strides - LNetCon2Size + 1 ), (tmpMatPool1[0].cols/Strides  - LNetCon2Size + 1 ), CV_32FC1);
    }
    /*Conv1*/
    Conv(tmpMatIn, 1, matLNetCon1, CON1CHL, matLNetBase1,tmpMatCon1, Strides, isPadding);

    /*Pool1*/
    Pool(tmpMatCon1, CON1CHL, tmpMatPool1, LNetPool1Size, PoolStrides, isPadding);

    /*Conv2*/
    Conv(tmpMatPool1, CON1CHL, matLNetCon2, CON2CHL, matLNetBase1, tmpMatcon2, Strides, isPadding);

   // cout<<tmpMatCon1[0]<<endl;
   // cout<<tmpMatCon1[2]<<endl;

    return crossEntropy;
}

/*mat Conv ,Return Result*/
float LeNet::matConvFun(Mat matIn, Mat MatConv, int row, int col)
{
    int i=0;
    int j=0;
    float sum = 0.0;

    for(i=row;i<(row+LNetCon1Size);i++)
    {
        for(j=col;j<(col+LNetCon1Size);j++)
        {
             sum += matIn.at<float>(i,j) * MatConv.at<float>(i-row,j-col);
        }
    }
    return sum;

}

int LeNet::Conv(Mat matIn[], int InNum, Mat matConv[], int ConNum, Mat matBias[], Mat matOut[], int Strides, int isPadding)
{
    int i;
    int j;
    int TmpInNum = 0;
    int TmpConNum = 0;

    if(isPadding == 0)
    {
        for(TmpConNum=0;TmpConNum<ConNum;TmpConNum++)
        {
            for(TmpInNum=0;TmpInNum<InNum;TmpInNum++)
            {
                for(i=0;i<(LNetImgSize/Strides - LNetCon1Size + 1);i+=Strides)
                {
                    for(j=0;j<(LNetImgSize/Strides - LNetCon1Size + 1);j+=Strides)
                    {
                        matOut[TmpConNum].at<float>(i/Strides,j/Strides) = matConvFun(matIn[TmpInNum],matConv[ConNum],i,j) + matBias[TmpConNum].at<float>(i/Strides,j/Strides);
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

/*Pooling*/
int LeNet::Pool(Mat matIn[], int InNum, Mat matOut[], int poolSize, int Strides, int isPadding)
{
    int i = 0;
    int j = 0;
    int tmpInNum=0;
    if(isPadding == 0)
    {
        for(tmpInNum=0;tmpInNum<InNum;tmpInNum++)
        {
             for(i=0;i<matIn[tmpInNum].rows;i+=Strides)
             {
                 cout<<"matIn[tmpInNum].rows"<<matIn[tmpInNum].rows<<endl;
                 for(j=0;j<matIn[tmpInNum].cols;j+=Strides)
                 {
                     matOut[tmpInNum].at<float>(i/Strides,j/Strides) = matPoolMax(matIn[tmpInNum], poolSize, i, j);
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



/*pool max value*/
float LeNet::matPoolMax(Mat matIn, int poolSize, int row, int col)
{
    float maxValue = 0;
    int i;
    int j;

    maxValue = matIn.at<float>(row,col);
    for(i=row;i<(row+poolSize);i++)
    {
        for(j=col;j<(col+poolSize);j++)
        {
             if(maxValue < matIn.at<float>(row+i,col+j))
             {
                 maxValue = matIn.at<float>(row+i,col+j);
             }
        }
    }
    return maxValue;
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
        matIn = imread(ImageName, 0);

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
    matIn = imread(ImageName, 0);

    /*ForwardPgt*/
    LeNetForWard(matIn, matReal, isTrue, expectValue);
    cout<<"isTrue"<<isTrue<<endl;

    return OK;
}
