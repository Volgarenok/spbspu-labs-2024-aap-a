#include "saddleElement.h"
int kiselev::saddleElement(int* array, size_t m, size_t n)
{
  int count = 0;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      bool min = isMinInRow(array, n, i, j);
      bool max = isMaxInColumn(array, m, n, i, j);
      if (min && max)
      {
        count++;
      }
    }
  }
  return count;
}

