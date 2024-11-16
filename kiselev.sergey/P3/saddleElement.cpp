#include "saddleElement.h"
bool isMinInRow(const int* array, size_t n, size_t i, size_t j)
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
bool isMaxInColumn(const int* array, size_t m, size_t n, size_t i, size_t j)
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
int kiselev::saddleElement(const int* array, size_t m, size_t n)
{
  int count = 0;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      bool min = isMinInRow(array, n, i, j);
      bool minAndMax = min && isMaxInColumn(array, m, n, i, j);
      if (minAndMax)
      {
        count++;
      }
    }
  }
  return count;
}

