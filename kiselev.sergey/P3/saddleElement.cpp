#include "saddleElement.h"
int kiselev::saddleElement(int* array, size_t m, size_t n)
{
  int count = 0;
  bool max = true, min = true;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      for (size_t k = 0; k < m; ++k)
      {
        if (array[i * n + j] < array[k * m + j])
        {
          max = false;
          break;
        }
      }
      for (size_t l = 0; l < n; ++l)
      {
        if (array[i * n + j] > array[i * n + l])
        {
          min = false;
          break;
        }
      }
      if (max && min)
      {
        count++;
      }
    }
  }
  return count;
}

