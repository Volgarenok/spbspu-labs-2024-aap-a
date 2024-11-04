#include <iostream>
#include <fstream>
#include "func.h"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Not enough arguments";
        return 1;
    }
    else if (argc > 2) {
        std::cerr << "Too many arguments";
        return 1;
    }
    else if (argv[0] == "1")
    {
        int mtx[10000] = {};
        int a[2] = {};
        try
        {
            matrixAutoInitialization(mtx, argv[1], a[0], a[1]);
        }
        catch (std::logic_error)
        {
            return 2;
        }
        matrixHandling(mtx, a[0], a[1]);
        matrixPush(mtx, argv[2], a[0], a[1]);
    }
    else if (argv[0] == "2")
    {
        int* mtx = nullptr;
        int a[2] = {};
        try
        {
            matrixDynamicInitialization(mtx, argv[1], a[0], a[1]);
        }
        catch (std::logic_error)
        {
            delete[] mtx;
            return 2;
        }
        matrixHandling(mtx, a[0], a[1]);
        matrixPush(mtx, argv[2], a[0], a[1]);
        delete[] mtx;
    }
    else
    {
        std::cerr << "First parameter is not a number";
        return 1;
    }
    return 0;
}
