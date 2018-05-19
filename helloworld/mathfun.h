#ifndef MATHFUN_H
#define MATHFUN_H

#include "stddatatype.h"



class MathFun
{
public:
    MathFun();

public:
    int LinerFun(int x);

    float GaussianFun(int x, int y, uint8 FilterSize, float sigma);

private:

protected:

};

#endif // MATHFUN_H
