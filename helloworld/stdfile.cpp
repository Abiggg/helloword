#include "stdfile.h"

using namespace std;

uint32 readLable(string sLableRoot, int *TrainLable, int TrainNum)
{
    int i = 0;
    string line;
    ifstream rfile;
    rfile.open(sLableRoot,ios_base::in);
    if(!rfile.is_open())
    {
        cout<<"open file fail"<<endl;
    }
    while (getline(rfile, line))
    {
        if(i < TrainNum)
        {
            *(TrainLable + i) = atoi(line.c_str());
            i++;
        }
        else
        {
            break;
        }

    }
    return OK;
}
