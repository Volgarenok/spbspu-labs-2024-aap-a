#include "matrixPush.hpp"
#include <fstream>

void asafov::matrixPush(int* mtx, char* output, int n, int m)
{
  std::ofstream fout(output);
  fout << n << ' ' << m << ' ';
  for (int i = 0; i < n * m; i++) {
    fout << mtx[i] << ' ';
  }
  fout.close();
}

void asafov::matrixPush(int n, char* output)
{
  std::ofstream fout(output);
  fout << n;
  fout.close();
}
