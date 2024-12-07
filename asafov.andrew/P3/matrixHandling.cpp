#include "matrixHandling.hpp"

void asafov::handleLftTopClk(int*& mtx, unsigned long long n, unsigned long long m)
{
  unsigned long long count = 1;
  unsigned long long e = n;
  unsigned long long r = m;
  unsigned long long a = -1;
  while (e * r != 0)
  {
    for (unsigned long long i = 0; i < r; i++)
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
    for (unsigned long long i = 0; i < e; i++)
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
    for (unsigned long long i = 0; i < r; i++)
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
    for (unsigned long long i = 0; i < e; i++)
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

unsigned long long asafov::handleNumColLsr(int* mtx, unsigned long long n, unsigned long long m)
{
  unsigned long long count = 0;
  unsigned long long maxCount = 0;
  unsigned long long maxMaxCount = 0;
  unsigned long long c = 0;
  size_t i = 0;
  for (; i < m; i++)
  {
    for (size_t e = 0; e < n-1; e++)
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
