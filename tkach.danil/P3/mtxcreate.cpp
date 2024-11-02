#include "mtxlogic.h"
#include <exception>

double* tkach::createMtx2(const int* const mtx, const size_t str, size_t stl)
{
  double* mtx2 = nullptr;
  try
  {
    mtx2 = new double[str * stl];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] mtx2;
    throw;
  }
  for (size_t i = 0; i < str; ++i)
  {
    for (size_t j = 0; j < stl; ++j)
    {
        double num = 0, sum = 0;
          if (i > 0) {
              num++;
              sum += mtx[i * stl + j - stl];
              if (j > 0) {
                  num++;
                  sum += mtx[i * stl + j - stl - 1];
              }
              if (j + 1 < stl) {
                  num++;
                  sum += mtx[i * stl + j - stl + 1];
              }
          }
          if (j > 0) {
              num++;
              sum += mtx[ i * stl + j - 1];
          }
          if (j + 1 < stl) {
              num++;
              sum += mtx[i * stl + j + 1];
          }
            if (i < str - 1)
            {
              num++;
              sum += mtx[i * stl + j + stl];
              if (j > 0) {
                  num++;
                  sum += mtx[i * stl + j + stl - 1];
              }
              if (j + 1 < stl) {
                  num++;
                  sum += mtx[i * stl + j + stl + 1];
              }
            }
          double sr = sum / num;
          mtx2[i * stl + j] = sr;
      }
  }
  return mtx2;
}
