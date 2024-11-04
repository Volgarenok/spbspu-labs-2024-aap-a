#include "matrix.hpp"

#include <limits>
#include <iostream>

std::istream & guseynov::inputMtx(std::istream &in, int *arr, size_t general, size_t& read)
{
  for (size_t i = 0; i < general; i++)
  {
    in >> arr[i];
    if (in.good())
    {
      read++;
    }
  }
  return in;
}

size_t guseynov::searchNumLogMin(const int *arr, size_t general)
{
  int min = std::numeric_limits < int >::max();
  size_t res = 0;
  for (size_t i = 1; i < general-1; i++)
  {
    if ((arr[i] <= min) && (arr[i-1] > arr[i]) && (arr[i+1] > arr[i]))
    {
      if (arr[i] == min)
      {
        res++;
      }
      else
      {
        res = 1;
        min = arr[i];
      }
    }
  }
  if ((res + 2) == general)
  {
    return 0;
  }
  return res;
}
