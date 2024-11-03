#include "saddleElement.h"
bool kiselev::isMinInRow(int* array, size_t n, size_t i, size_t j)
{
  for (size_t k = 0; k < n; ++k)
  {
    if (array[i * n + j] > array[i * n + k])
    {
      return false;
    }
  }
  return true;
}
