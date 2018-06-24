#include <stdlib.h>
#include <iostream>

#include "mathlib.h"

using namespace std;


/*rand value function (-1, 1)*/
float GetRamdom_B1_1()
{
     return 2.0 * (float)rand() / RAND_MAX -1;
}

/*MatReal Transform*/
uint32 MatRealTransform(int num, Mat &matReal)
{
    matReal = Mat::zeros(1,10, CV_8U);
    if (num < 10)
    {
        matReal.at<uchar>(0,num) = 1;
    }
    return OK;
}

/*Sigmoid Function-->test ok*/
float Sigmoid(float x, int sigmoidA)
{
     return 1/(1 + exp(-1.0 /(float)sigmoidA  * x));
}

/*Diff Sigmoid-->test ok*/
float DiffSigmoid(float x, int sigmoidA)
{
     return 1.0 /(float)sigmoidA * (x * (1 - x));
}

/*Transform Mat By Sigmoid Function---->test ok*/
void MatSigmoid(Mat matIn, Mat &matOut, Mat& matDiffSigmoid, int sigmoidA)
{
    int j;

    for(j=0;j<matIn.cols;j++)
    {
        matOut.at<float>(0,j) = Sigmoid(matIn.at<float>(0,j), sigmoidA);
        matDiffSigmoid.at<float>(0,j) = DiffSigmoid(matOut.at<float>(0,j), sigmoidA);
    }
}

/*Transform Mat By Softmat Fun--testok*/
void MatSoftmax(Mat matIn, Mat &matOut)
{
    int i = 0;
    float sum = 0;
    for(i=0;i<matIn.cols;i++)
    {
        sum += exp(matIn.at<float>(0, i));
    }
    for(i=0;i<matIn.cols;i++)
    {
         matOut.at<float>(0, i)= exp(matIn.at<float>(0, i))/sum;
    }
}

/*count Diff of softmax--testok*/
void MatDiffSoftmax(Mat matOut, int pos, Mat matDiffSoftmax)
{
    int i;
    for(i=0;i<matOut.cols;i++)
    {
        if(i == pos)
        {
            matDiffSoftmax.at<float>(0, i) = matOut.at<float>(0, i) * (1 - matOut.at<float>(0, i));
        }
        else
        {
            matDiffSoftmax.at<float>(0, i) = - matOut.at<float>(0, pos) * matOut.at<float>(0, i);
        }
    }
}


/*Cout CrossEntropy-->testok*/
float MatCrossEntropy(Mat matFct, Mat matReal, float& matDiffCrossEntropy, int& pos)
{
    int i ;
    float CrossEntropy = 0.0;

    for(i=0;i<matFct.cols;i++)
    {
        if((int)(matReal.at<uchar>(0,i)) >= 1)
        {
            CrossEntropy = (float)log((double)matFct.at<float>(0,i)) *(-1);
            matDiffCrossEntropy = (-1.0) / matFct.at<float>(0,i);
            pos = i;
        }
        else
        {
            continue;
        }
    }
    return CrossEntropy;
}

/*Mat plus in line*/
Mat MatPlus(Mat matA, Mat matB)
{
    int i;
    Mat matOut = Mat::zeros(1, matA.cols, CV_32F);
    for(i=0;i<matA.cols;i++)
    {
        matOut.at<float>(0,i) = matA.at<float>(0,i) * matB.at<float>(0,i);
    }
    return matOut;
}

Mat MatReverse(Mat matX, Mat matY)
{
    int i;
    int j;
    Mat matWeight = Mat::zeros(matX.cols, matY.cols, CV_32F);
    for(i=0;i<matX.cols;i++)
    {
        for(j=0;j<matY.cols;j++)
        {
            matWeight.at<float>(i,j) = matX.at<float>(0,i) * matY.at<float>(0,j);
        }
    }
    return matWeight;
}

/*Mat Combine*/
Mat MatCombine(Mat matX)
{
    int i;
    int j;
    Mat matOut = Mat::zeros(1, matX.rows, CV_32F);
    for(i=0;i<matX.rows;i++)
    {
        for(j=0;j<matX.cols;j++)
        {
            matOut.at<float>(0,i) += matX.at<float>(i,j);
        }
    }
    return matOut;
}

int MatMaxfloat(Mat matX)
{
    int i;
    int pos = 0;
    float Value = matX.at<float>(0,0);
    for(i=1;i<matX.cols;i++)
    {
        if(matX.at<float>(0,i) > Value)
        {
            Value = matX.at<float>(0,i);
            pos = i;
        }
    }
    return pos;
}

int MatMaxInt(Mat matX)
{
    int i;
    for(i=0;i<matX.cols;i++)
    {
        if((int)(matX.at<uchar>(0,i)) >= 1)
        {
            return i;
        }
    }
    return ERROR;
}


/*Decay Rate*/
float DecayRate(float learnRate, float decay_rate,int global_step, int decay_steps)
{
    float tmplearnRate;
    tmplearnRate = learnRate * pow(decay_rate, global_step / decay_steps);
    return tmplearnRate;
}

/*Relu active*/
float Relu(float x)
{
    if(x > 0)
    {
        return x;
    }
    else
    {
        return 0.0;
    }
}

/*Diff Relu*/
float DiffRelu(float x)
{
    if(x >0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*Transform mat by Relu fun*/
void MatRelu(Mat matIn, Mat &matOut, Mat &matDiffRelu)
{
    int j;

    for(j=0;j<matIn.cols;j++)
    {
        matOut.at<float>(0,j) = Relu(matIn.at<float>(0,j));
        matDiffRelu.at<float>(0,j) = DiffRelu(matIn.at<float>(0,j));
    }
}
