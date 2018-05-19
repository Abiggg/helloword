#include "mathfun.h"
#include "math.h"

MathFun::MathFun()
{



}

int MathFun::LinerFun(int x)
{
    return x;
}

float MathFun::GaussianFun(int x, int y, uint8 FilterSize, float sigma)
{
    /*G(x,y) = 1/(2*pi*sigma^2)*e^(-(x^2+y^2)/(2*sigma^2))*/
    float gaussian_temp;
    gaussian_temp = exp(-(pow(x-FilterSize/2,2)+pow(y-FilterSize/2,2))/(2*pow(sigma,2)))/(2*PI*pow(sigma,2));
    return gaussian_temp;
}
