#include <stdlib.h>
#include <iostream>

#include "mathlib.h"

using namespace std;


/*rand value function (-1, 1)*/
double GetRamdom_B1_1()
{
     return 2.0 * (double)rand() / RAND_MAX -1;
}

/*Sigmoid Function*/
double Sigmoid(double x)
{
     return 1/(1+exp(-x));
}
