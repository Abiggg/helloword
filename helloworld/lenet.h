#ifndef LENET_H
#define LENET_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "stddatatype.h"

#include <sstream>
using namespace cv;
using namespace std;

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
   Mat LNetCon1[6];
   Mat LNetCon2[16];

   Mat LNetCon1Sum[6];
   Mat LNetCon2Sum[16];

   int* LNetTrainLable;
   bool LNetReadDataLock;

private:
   int LeNetMatInit();

   int LeNetDataInit();

   float LeNetForWard(Mat matIn, Mat matReal, bool& isTrue, int& expectValue);


};

#endif // LENET_H
