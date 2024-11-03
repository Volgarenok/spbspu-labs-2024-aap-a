#include <cstddef>
#include "saddleElement.h"
bool kiselev::isMaxInColumn(int* array, size_t m, size_t n, size_t i, size_t j)
{
  for (size_t l = 0; l < m; ++l)
  {
    if (array[i * n + j] < array[l * n + j])
    {
      return false;
    }
  }
  return true;
}
