#ifndef DATAST_H
#define DATAST_H

#include "stddatatype.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

typedef struct DoubleLq DoubleLq_S;
typedef struct DoubleLq* pDoubleLq_S;

struct DoubleLq
{
public:
    DoubleLq *pLast;
    DoubleLq *pNext;
    uint32 count;
    Mat mat;

    /*Init DoubleLq*/
    uint32 DoubleLqInit(pDoubleLq_S *SavedLq,  Mat matIn);
    /*creat node*/
    uint32 DoubleLqAddNode(pDoubleLq_S SavedLq,  Mat matIn);
    /*Delet node*/
    uint32 DoubleLqDeletRearNode(pDoubleLq_S SavedLq);
    /*Get Last mat*/
    uint32 DoubleLqGetLast(pDoubleLq_S SavedLq, Mat& matLast);
    /*Destory 2nd node*/
    uint32 DoubleLqDelet2ndNode(pDoubleLq_S SavedLq);
private:

protected:

};

#endif // DATAST_H
