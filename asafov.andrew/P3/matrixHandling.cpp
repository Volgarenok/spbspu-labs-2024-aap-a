#include "matrixHandling.hpp"

void asafov::matrixHandling(int* mtx, size_t n, size_t m)
{
  int count = 1;
  int e = n;
  int r = m;
  int a = -1;
  while (e * r != 0)
  {
    for (int i = 0; i < r; i++)
    {
      a++;
      mtx[a] -= count;
      count++;
    }
    if (e * r == 0)
    {
      break;
    }
    e--;
    for (int i = 0; i < e; i++)
    {
      a += m;
      mtx[a] -= count;
      count++;
    }
    if (e * r == 0)
    {
      break;
    }
    r--;
    for (int i = 0; i < r; i++)
    {
      a--;
      mtx[a] -= count;
      count++;
    }
    if (e * r == 0)
    {
      break;
    }
    e--;
    for (int i = 0; i < e; i++)
    {
      a -= m;
      mtx[a] -= count;
      count++;
    }
    if (e * r == 0)
    {
      break;
    }
    r--;
  }
}

int asafov::matrixHandlingSanctions(int* mtx, size_t n, size_t m)
{
  int count = 0;
  int maxCount = 0;
  int maxMaxCount = 0;
  int c = 0;
  int i = 0;
  for (; i < m; i++)
  {
    for (int e = 0; e < n-1; e++)
    {
      if (mtx[e * m + i] == mtx[(e + 1) * m + i])
      {
        count++;
      }
      else
      {
        maxCount = count;
        count = 0;
      }
    }
    maxCount = count;
    if (maxCount > maxMaxCount)
    {
      maxMaxCount = maxCount;
      c = i;
    }
    maxCount = 0;
    count = 0;
  }
  return c + 1;
}
