#ifndef MATHLIB_H
#define MATHLIB_H

#include <math.h>
#include <stdlib.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "stddatatype.h"

using namespace cv;
using namespace std;

/*rand value function (-1, 1)*/
float GetRamdom_B1_1();

/*Sigmoid function*/
float Sigmoid(float x, int sigmoidA);
float DiffSigmoid(float x, int sigmoidA);
/*Transform mat by sigmoid fun*/
void MatSigmoid(Mat matIn, Mat& matOut, Mat& matDiffSigmoid, int sigmoidA);

/*Relu ativate*/
float Relu(float x);
float DiffRelu(float x);
/*Transform mat by Relu fun*/
void MatRelu(Mat matIn, Mat& matOut, Mat& matDiffSigmoid);

/*mat softmax*/
void MatSoftmax(Mat matIn, Mat& matOut);

void MatDiffSoftmax(Mat matOut, int pos, Mat matDiffSoftmax);

/*cout cross Entropy*/
float MatCrossEntropy(Mat matFct, Mat matReal, float& matDiffCrossEntropy, int& pos);

/*MatRealTransform*/
uint32 MatRealTransform(int num, Mat& matReal);

/*Mat Plus in line*/
Mat MatPlus(Mat matA, Mat matB);

/*Mat reverse*/
Mat MatReverse(Mat matX, Mat matY);

Mat MatCombine(Mat matX);

int MatMaxfloat(Mat matX);

int MatMaxInt(Mat matX);

/*Decay rate*/
float DecayRate(float learnRate, float decay_rate, int global_step, int decay_steps);

#endif // MATHLIB_H
