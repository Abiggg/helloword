#ifndef MATHFUN_H
#define MATHFUN_H

#include "stddatatype.h"
#include "mathfun.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

#include "stddatatype.h"
#include "math.h"


class MathFun
{
public:
    MathFun();

public:

    /*binary function*/
    int Binary(int x);

    int DataTranstrom(float x);

    /*Liner Fun*/
    int LinerFun(int x);

    /*Gaussian Function*/
    float GaussianFun(int x, int y, uint8 FilterSize, float sigma);

    /*Count RBG Mean*/
    uint32 CountRgbMean(Mat MatIn, uint8 RgbMean[3]);

    /*Count RBG Max and Min*/
    uint32 CountRgbMaxMin(Mat MatIn, uint8 RgbMax[3], uint8 RgbMin[3]);

    uint32 CoutClassical(uint32 RgbSrc[3],uint32 RgbDst[3]);


    /*pix limit*/
    int PixLimit(int x);
private:

protected:

};

#endif // MATHFUN_H
