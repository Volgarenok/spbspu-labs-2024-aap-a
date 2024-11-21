#include "matrix.hpp"

#include <limits>
#include <iostream>

std::istream & guseynov::inputMtx(std::istream &in, int *arr, size_t generalLength, size_t& read)
{
  for (size_t i = 0; i < generalLength; i++)
  {
    if (in >> arr[i])
    {
      read++;
    }
  }
  return in;
}

size_t guseynov::searchNumLocMin(const int *arr, size_t generalLength)
{
  int min = std::numeric_limits< int >::max();
  size_t res = 0;
  for (size_t i = 1; i < generalLength - 1; i++)
  {
    if ((arr[i] <= min) && (arr[i - 1] > arr[i]) && (arr[i + 1] > arr[i]))
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
  if ((res + 2) == generalLength)
  {
    return 0;
  }
  return res;
}
