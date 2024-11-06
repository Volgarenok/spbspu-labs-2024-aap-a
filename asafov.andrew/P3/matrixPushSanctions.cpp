#include <fstream>
#include "func.h"

void matrixPush(int n, char* output)
{
    std::ofstream fout(output);
    fout << n;
    fout.close();
}
