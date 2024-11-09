#include <fstream>
#include "func.hpp"

void matrixHandling(int* mtx, int n, int m)
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
