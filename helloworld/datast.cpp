#include "datast.h"

/*Init a double Lq*/
unsigned int DoubleLq::DoubleLqInit(pDoubleLq_S *SavedLq, Mat matIn)
{
    *SavedLq = new DoubleLq_S;
    if(*SavedLq == NULL)
    {
        return ERROR;
    }
    else
    {
        (*SavedLq)->mat = matIn;
        (*SavedLq)->pLast = NULL;
        (*SavedLq)->pNext = NULL;
        (*SavedLq)->count = 1;
    }
    return OK;
}

/*Double Lq add a node at top*/
unsigned int DoubleLq::DoubleLqAddNode(pDoubleLq_S SavedLq, Mat matIn)
{
    pDoubleLq_S new_node = new DoubleLq_S;
    pDoubleLq_S temp = SavedLq;
    if(SavedLq == NULL)
    {
        return ERROR;
    }
    if(new_node == NULL)
    {
        return ERROR;
    }

    /*new node init*/
    new_node->mat = matIn;
    new_node->pNext = NULL;

    /*add new node at last*/
    while(temp->pNext)
    {
        temp = temp->pNext;
    }
    temp->pNext = new_node;
    new_node->pLast = temp;
    count ++;

    return OK;
}

/*Delet last Node*/
unsigned int DoubleLq::DoubleLqDeletRearNode(pDoubleLq_S SavedLq)
{
    pDoubleLq_S temp = SavedLq;
    if(temp == NULL)
    {
        return ERROR;
    }
    else
    {
        while (temp->pNext)
        {
            temp = temp->pNext; /*find the last value*/
        }
        temp = temp->pLast; /*find the last 2 value*/
        delete temp->pNext; /*delete the last value*/
        temp->pNext = NULL;
    }
    return OK;
}

/*Get Last mat*/
unsigned int DoubleLq::DoubleLqGetLast(pDoubleLq_S SavedLq, Mat& matLast)
{
    pDoubleLq_S temp = SavedLq;
    if(temp == NULL)
    {
        return ERROR;
    }
    else
    {
        while(temp->pNext)
        {
            temp = temp->pNext;
        }
        matLast = temp->mat;
    }
    return OK;
}

/*DeletTopNode*/
unsigned int DoubleLq::DoubleLqDelet2ndNode(pDoubleLq_S SavedLq)
{
    pDoubleLq_S tempA = SavedLq;
    pDoubleLq_S tempB = SavedLq;
    if(tempA == NULL || tempB == NULL)
    {
        return ERROR;
    }
    else
    {
        tempA = tempA->pNext;
        tempB->pNext = tempA->pNext;
        tempA->pNext->pLast = tempB;
        delete tempA;
        tempA->pNext = NULL;
        tempA->pLast = NULL;
    }
    return OK;
}









