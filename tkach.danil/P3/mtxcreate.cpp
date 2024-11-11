#include "mtxlogic.h"

double* tkach::createMtx2(const int* const mtx, const size_t row_size, const size_t column_size)
{
  double* mtx2 = new double[row_size * column_size];
  for (size_t i = 0; i < row_size; ++i)
  {
<<<<<<< HEAD
    mtx2 = new double[str * stl];
  }
  catch (const std::bad_alloc & e)
  {
    return nullptr;
  }
  for (size_t i = 0; i < str; ++i)
  {
    for (size_t j = 0; j < stl; ++j)
=======
    for (size_t j = 0; j < column_size; ++j)
>>>>>>> tkach.danil/P3
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
  return mtx2;
}
