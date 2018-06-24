#ifndef BPNETWORK_H
#define BPNETWORK_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "stddatatype.h"

#include <sstream>
using namespace cv;
using namespace std;

class BpNetwork
{
public:
    string sLableRoot;
    string sImageRoot;
    string sSaveRoot;

    int inNum;
    int hdNum;
    int OutNum;

    float LearingRate;
    int BatchSize;
    int TrainNum;

    float CrossEntropy;
public:
    BpNetwork();
    ~BpNetwork();
    uint32 BpNetWortInit();
    uint32 BpNetWorkTrain();
    uint32 BpNetWorkTest(int TestNum, Mat& matIn, int& expectValue, bool& isTrue);
    uint32 BpNetWorkSaveData();

public:
    uint32 MatToLine(Mat matIn, Mat& matOut);
    uint32 MatInit();
    uint32 DataInit();
    float BpForwardPgt(Mat matIn, Mat matReal, bool& isTrue, int& expectValue);
    uint32 WeightBiasAdj();

private:
    Mat matWeightInHd;
    Mat matBiasInHd;
    Mat matWeightHdOut;
    Mat matBiasHdOut;

    Mat matWeightInHdSum;
    Mat matBiasInHdSum;
    Mat matWeightHdOutSum;
    Mat matBiasHdOutSum;

    int* TrainLable;
    bool BpReadDataLock;

};

#endif // BPNETWORK_H
