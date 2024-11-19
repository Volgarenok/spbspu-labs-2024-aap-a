#include "quantity_loc_max.h"

bool finaev::is_loc_max(const int* a, size_t stl, size_t i, size_t j)
{
  size_t t = i * stl + j;
  bool is_loc_max = (a[t] > a[t - 1]) && (a[t] > a[t + 1]);
  is_loc_max = is_loc_max && (a[t] > a[t - stl - 1]) && (a[t] > a[t - stl]) && (a[t] > a[t - stl + 1]);
  is_loc_max = is_loc_max && (a[t] > a[t + stl - 1]) && (a[t] > a[t + stl]) && (a[t] > a[t + stl + 1]);
  return is_loc_max;
}

size_t finaev::quantity_loc_max(const int* matrix, size_t strk, size_t stl)
{
  size_t res = 0;
  for (size_t i = 1; i < strk - 1; i++)
  {
    for (size_t j = 1; j < stl - 1; j++)
    {
      if (is_loc_max(matrix, stl, i, j) == true)
      {
        res++;
      }
    }
  }
  return res;
}
