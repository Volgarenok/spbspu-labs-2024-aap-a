#include <fstream>
#include "func.h"

void matrixPush(int* mtx, char* output, int n, int m)
{
    std::ofstream fout(output);
    fout << n << ' ' << m << ' ';
    for (int i = 0; i < n * m; i++) {
        fout << mtx[i] << ' ';
    }
}
