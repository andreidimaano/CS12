#include "minFunc.h"
const int * min(const int arr[], int arrSize) 
{
    if(arrSize == 0)
    {
        return 0;
    }
    if(arrSize == 1)
        
    {
        return arr;
    }
    const int* minL = min(arr + 1, arrSize - 1);
    if(*arr <= *minL)
    {
        return arr;
    }
    if(*minL <= *arr)
    {
        return minL;
    }
    return arr;
}