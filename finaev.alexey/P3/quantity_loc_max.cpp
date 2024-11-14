#include "quantity_loc_max.h"

int finaev::quantity_loc_max(const int* matrix, size_t strk, size_t stl)
{
  int res = 0;
  int temp = 0;
  for (size_t i = 1; i < strk - 1; i++)
  {
    for (size_t j = 1; j < stl - 1; j++)
    {
      for (size_t z = stl - 1; z <= strk + 1; z++)
      {
        if (matrix[i * stl + j] <= matrix[i * stl + j - z])
        {
          break;
        }
        if (matrix[i * stl + j] <= matrix[i * stl + j + z])
        {
          break;
        }
        if (matrix[i * stl + j] <= matrix[i * stl + j - 1])
        {
          break;
        }
        if (matrix[i * stl + j] <= matrix[i * stl + j + 1])
        {
          break;
        }
        temp++;
        if (temp == 3)
        {
          res++;
          temp = 0;
        }
      }
    }
  }
  return res;
}
