#include <fstream>
#include "func.h"

int matrixHandlingSanctions(int* mtx, int n, int m)
{
    int count = 0;
    int maxCount = 0;
    int maxMaxCount = 0;
    int c = 0;
    int i = 0;
    for (; i < m; i++)
    {
        for (int e = 0; e < n-1; e++)
        {
            if (mtx[e * m + i] == mtx[(e + 1) * m + i])
            {
                count++;
            }
            else
            {
                maxCount = count;
                count = 0;
            }
            


        }
        maxCount = count;
        if (maxCount > maxMaxCount)
        {
            maxMaxCount = maxCount;
            c = i;
        }
        maxCount = 0;
        count = 0;
    }
    return c + 1;
}
