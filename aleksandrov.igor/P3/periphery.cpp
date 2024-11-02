#include "periphery.h"

void aleksandrov::periphery(int* array, size_t m, size_t n)
{
  int p1 = 0, p2 = (m - 1), q1 = 0, q2 = (n - 1), count = 1;
  while (p1 <= p2 || q1 <= q2)
  {
    for (int i = p1; i <= p2; ++i)
    {
      for (int j = q1; j <= q2; ++j)
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
}
