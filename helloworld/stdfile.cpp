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
        return ERROR;
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

unsigned int SaveBpTrainValue(string SaveRoot, Mat saveMat0, Mat saveMat1, Mat saveMat2, Mat saveMat3)
{
    int i;
    int j;
    ofstream foi(SaveRoot, ios::out);
    string line = "";
    if(!foi.is_open())
    {
        cout<<"open file fail"<<endl;
        return ERROR;
    }
    for(i=0;i<saveMat0.rows;i++)
    {
        for(j=0;j<saveMat0.cols;j++)
        {
            line += to_string(saveMat0.at<float>(i,j))+",";
        }
        foi << line + "\n";
        line = "";
    }
    line = "\n";
    foi << line;
    for(i=0;i<saveMat1.rows;i++)
    {
        for(j=0;j<saveMat1.cols;j++)
        {
            line += to_string(saveMat1.at<float>(i,j))+",";
        }
        foi << line + "\n";
        line = "";
    }
    line = "\n";
    foi << line;
    for(i=0;i<saveMat2.rows;i++)
    {
        for(j=0;j<saveMat2.cols;j++)
        {
            line += to_string(saveMat2.at<float>(i,j))+",";
        }
        foi << line + "\n";
        line = "";
    }
    line = "\n";
    foi << line;
    for(i=0;i<saveMat3.rows;i++)
    {
        for(j=0;j<saveMat3.cols;j++)
        {
            line += to_string(saveMat3.at<float>(i,j))+",";
        }
        foi << line + "\n";
        line = "";
    }

    foi.close();
    return OK;
}

unsigned int ReadBpTrainValue(string SaveRoot, Mat &saveMat0, Mat &saveMat1, Mat &saveMat2, Mat &saveMat3)
{
    int i;
    int j;
    int k;
    int l = 0;
    char cline[10000] = {0};
    char value[50] = {0};
    ifstream rfile(SaveRoot, ios::in);
    if(!rfile.is_open())
    {
        cout<<"open file fail"<<endl;
        return ERROR;
    }
    for(i=0;i<saveMat0.rows;i++)
    {
        j = 0;
        rfile.getline(cline, 10000);
        for(k=0;k<10000;k++)
        {
            if(cline[k] == '\n')
            {
                break;
            }
            if(j >= saveMat0.cols)
            {
                break;
            }
            if(cline[k] != ',')
            {
                 value[l] = cline[k];
                 l += 1;
            }
            else
            {
                 value[l] = '\n';
                 saveMat0.at<float>(i,j) = atof(value);
                 j += 1;
                 l = 0;
                 memset(value, 0 ,50);
            }
        }
    }
    rfile.getline(cline, 10000);
    rfile.getline(cline, 10000);
    for(i=0;i<saveMat1.rows;i++)
    {
        j = 0;
        rfile.getline(cline, 10000);

        for(k=0;k<10000;k++)
        {
            if(cline[k] == '\n')
            {
                break;
            }
            if(j >= saveMat1.cols)
            {
                break;
            }
            if(cline[k] != ',')
            {
                 value[l] = cline[k];
                 l += 1;
            }
            else
            {
                 value[l] = '\n';
                 saveMat1.at<float>(i,j) = atof(value);
                 j += 1;
                 l = 0;
                 memset(value, 0 ,50);
            }
        }
    }
    rfile.getline(cline, 10000);
    rfile.getline(cline, 10000);
    for(i=0;i<saveMat2.rows;i++)
    {
        j = 0;
        rfile.getline(cline, 10000);
        for(k=0;k<10000;k++)
        {
            if(cline[k] == '\n')
            {
                break;
            }
            if(j > saveMat2.cols)
            {
                break;
            }
            if(cline[k] != ',')
            {
                 value[l] = cline[k];
                 l += 1;
            }
            else
            {
                 value[l] = '\n';
                 saveMat2.at<float>(i,j) = atof(value);
                 j += 1;
                 l = 0;
                 memset(value, 0 ,50);
            }
        }
    }
    rfile.getline(cline, 10000);
    rfile.getline(cline, 10000);

    for(i=0;i<saveMat3.rows;i++)
    {
        j = 0;
        rfile.getline(cline, 10000);
        for(k=0;k<10000;k++)
        {
            if(cline[k] == '\n')
            {
                break;
            }
            if(j> saveMat3.cols)
            {
                break;
            }
            if(cline[k] != ',')
            {
                 value[l] = cline[k];
                 l += 1;
            }
            else
            {
                 value[l] = '\n';
                 saveMat3.at<float>(i,j) = atof(value);
                 j = j + 1;
                 l = 0;
                 memset(value, 0 ,50);
            }
        }
    }
    rfile.close();
    return OK;

}
