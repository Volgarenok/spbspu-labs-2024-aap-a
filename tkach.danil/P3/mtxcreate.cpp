#include "mtxlogic.h"

void tkach::buildNewMtxWithAverageElements(const int* const mtx, double* const mtx2, const size_t row_size, const size_t column_size)
{
  for (size_t i = 0; i < row_size; ++i)
  {
    for (size_t j = 0; j < column_size; ++j)
    {
      double num = 0, sum = 0, sr = 0;
      if (i > 0)
      {
        num++;
        sum += mtx[i * column_size + j - column_size];
        if (j > 0)
        {
          num++;
          sum += mtx[i * column_size + j - column_size - 1];
        }
        if (j + 1 < column_size)
        {
          num++;
          sum += mtx[i * column_size + j - column_size + 1];
        }
      }
      if (j > 0)
      {
        num++;
        sum += mtx[i * column_size + j - 1];
      }
      if (j + 1 < column_size)
      {
        num++;
        sum += mtx[i * column_size + j + 1];
      }
      if (i < row_size - 1)
      {
        num++;
        sum += mtx[i * column_size + j + column_size];
        if (j > 0)
        {
          num++;
          sum += mtx[i * column_size + j + column_size - 1];
        }
        if (j + 1 < column_size)
        {
          num++;
          sum += mtx[i * column_size + j + column_size + 1];
        }
      }
      sr = sum / num;
      mtx2[i * column_size + j] = sr;
    }
  }
}
