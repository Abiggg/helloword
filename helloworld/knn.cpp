#include "knn.h"
#include "stdfile.h"
#include <algorithm>

Knn::Knn()
{

}

/*Init K*/
void Knn::vectorInit()
{
    sortDistance.resize(typeNum);
    for(int i=0;i<typeNum;i++)
    {
        sortDistance[i].resize(kNum/typeNum+1);
    }
}

/*kNode struct Init*/
void Knn::kStructInit()
{
    KNN_NODE_S* node = new KNN_NODE_S;
}

/*Init K*/
unsigned int Knn::DataInit()
{
    TrainLable = new int[knnTrainNum];
    readLable(sKnnLableRoot, TrainLable, knnTrainNum); /*Get Lable from lable.txt*/

    return OK;
}

/*Count the distance between train Image and Test Image*/
double Knn::KnnCountDistance(Mat matIn, Mat matTest)
{
    double sq = 0.0;
    for(int i=0;i<matIn.cols;i++)
    {
        sq += pow((double)(matTest.at<float>(0,i) - matIn.at<float>(0,i)), 2.0);
    }
    return pow(sq, 0.5);
}

/*Knn */
bool Knn::compare(int a,int b)
{
  return a<b; //升序排列
}

/*Sort the distance in vector*/
void Knn::KnnSortDistance(vector<vector<double>> sortDistance, double distance, int lable)
{
    sort(sortDistance[lable].begin(), sortDistance[lable].end());
    if(distance < sortDistance[lable][kNum/typeNum+1])
    {
        sortDistance[lable][kNum/typeNum+1] = distance;
    }
    sort(sortDistance[lable].begin(), sortDistance[lable].end());
}

/*Sort the min "k" distance vector*/
int Knn::KnnBestValue(vector<vector<double> > sortDistance)
{

}

void Knn::KnnTest()
{
    Mat matTest;
    Mat matIn;
    int lable;
    int distance;
    for(int i=totalNum-1;i>0;i--)
    {
        string TestImageName = sKnnImageRoot + to_string((int)i) + ".png";
        matTest = imread(TestImageName, 0);
        for(int j=0;j<knnTrainNum;j++)
        {
            /*Train data and lable in*/
            lable = *(TrainLable + j);
            string TrainImageName = sKnnImageRoot + to_string((int)j) + ".png";
            matIn = imread(TrainImageName, 0);
            threshold(matIn, matIn, 125, 255, CV_THRESH_BINARY);

            /*Save the distance*/
            distance = KnnCountDistance(matIn, matTest);
            KnnSortDistance(sortDistance, distance, lable);

            /**/
        }
    }

}


