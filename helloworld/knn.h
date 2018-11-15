#ifndef KNN_H
#define KNN_H

#include "vector"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "mathlib.h"
#include "stdfile.h"

using std::vector;
using namespace std;
using namespace cv;

#define totalNum 60000

typedef struct tagKNN_NODE
{
    int *plast;
    int type;
    double distance;
    int *pnext;
}KNN_NODE_S;

class Knn
{

public:
    Knn();
    void vectorInit();
    void kStructInit();
    uint32 DataInit();

    bool compare(int a,int b);

    /*Count distance*/
    double KnnCountDistance(Mat matIn, Mat matTest);

    /*Sort Distance*/
    void KnnSortDistance(vector<vector<double>> sortDistance, double distance, int lable);

    /*Knn BestValue*/
    int KnnBestValue(vector<vector<double>> sortDistance);

    /*Knn Test*/
    void KnnTest();

public:
    int kNum;
    int typeNum;
    int knnTrainNum;
    int* TrainLable;

    string sKnnImageRoot;
    string sKnnLableRoot;

    vector<vector<double>> sortDistance;

};

#endif // KNN_H
