#ifndef LENET_H
#define LENET_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "stddatatype.h"

#include <sstream>
using namespace cv;
using namespace std;

#define CON1CHL 3
#define CON2CHL 6

class LeNet
{
public:
    LeNet();
    ~LeNet();

public:
    string sLNetLableRoot;
    string sLNetImageRoot;
    string sLNetSaveRoot;

    int LNetImgSize;
    int LNetFc2Num;
    int LNetFc3Num;
    int LNetTypeNum;

    int LNetCon1Size;
    int LNetCon1Chl;
    int LNetPool1Size;

    int LNetCon2Size;
    int LNetCon2Chl;
    int LNetPoo21Size;

    float LNetLearnRate;
    int LNetBatchSize;
    int LNetTrainNum;

    float LNetCrossEntropy;

public:
   int LeNetInit();
   int LeNetTrain();
   int LeNetTest(int TestNum, Mat& matIn, int& expectValue, bool& isTrue);


private:
   Mat matLNetCon1[CON1CHL];
   Mat matLNetBase1[CON1CHL];
   Mat matLNetCon2[CON2CHL];
   Mat matLNetBase2[CON2CHL];

   int* LNetTrainLable;
   bool LNetReadDataLock;

private:
   int LeNetMatInit();
   int LeNetDataInit();
   Mat MattoFloat(Mat matIn);
   float matConvFun(Mat matIn,Mat MatConv,int row, int col);
   float matPoolMax(Mat matIn, int poolSize, int row, int col);
   float LeNetForWard(Mat matIn, Mat matReal, bool& isTrue, int& expectValue);
   int Conv(Mat matIn[], int InNum, Mat matConv[], int ConNum, Mat matBias[], Mat matOut[], int Strides, int isPadding);
   int Pool(Mat matIn[], int InNum, Mat matOut[], int poolSize, int Strides, int isPadding);


};

#endif // LENET_H
