#ifndef STDFILE_H
#define STDFILE_H
#include <fstream>
#include <iostream>
#include <string.h>
#include "stddatatype.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


uint32 readLable(string sLableRoot, int *TrainLable, int TrainNum);

uint32 SaveBpTrainValue(string SaveRoot, Mat saveMat0, Mat saveMat1, Mat saveMat2, Mat saveMat3);

uint32 ReadBpTrainValue(string SaveRoot, Mat& saveMat0, Mat& saveMat1, Mat& saveMat2, Mat& saveMat3);

#endif // STDFILE_H
