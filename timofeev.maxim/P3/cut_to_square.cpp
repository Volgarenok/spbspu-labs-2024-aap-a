#include "cut_to_square.h"

int* timofeev::cut_to_square(const int* matrix, size_t strk, size_t stl)
{
  if (stl <= strk)
  {
    size_t capacity = stl * stl;
    int* new_mtx = new int[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
      new_mtx[i] = matrix[i];
    }
    delete[] new_mtx;
    return new_mtx;
  }
  else
  {
    size_t capacity = strk * strk;
    int* new_mtx = new int[capacity];
    size_t ind = 0;
    for (size_t i = 0; i <  strk * stl; i += stl)
    {
      for (size_t j = 0; j < strk; j++)
      {
        new_mtx[ind] = matrix[i + j];
        ind++;
      }
    }
    delete[] new_mtx;
    return new_mtx;
  }
}
