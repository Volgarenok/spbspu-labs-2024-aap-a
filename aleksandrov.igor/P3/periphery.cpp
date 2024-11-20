#include "periphery.h"

void aleksandrov::periphery(int* array, size_t m, size_t n)
{
  if (m == 0 || n == 0)
  {
    return;
  }
  size_t p1 = 0, p2 = m - 1, q1 = 0, q2 = n - 1;
  size_t count = 1;
  do
  {
    for (size_t i = p1; i <= p2; ++i)
    {
      for (size_t j = q1; j <= q2; ++j)
      {
        if (i == p1 || i == p2 || j == q1 || j == q2)
        {
          array[i * n + j] += count;
        }
      }
    }
    p1++;
    p2--;
    q1++;
    q2--;
    count++;
  }
  while (p1 <= p2 && q1 <= q2 && p1 < m && q1 < n);
}

