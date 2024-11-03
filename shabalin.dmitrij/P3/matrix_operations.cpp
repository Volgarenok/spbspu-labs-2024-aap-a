#include "matrix_operations.hpp"
#include <istream>

void shabalin::spiralDecrease(int *matrix, size_t rows, size_t cols)
{
  size_t left = 0, right = cols - 1, top = 0, bottom = rows - 1;
  int decreaseValue = 1;
  int count = 0;

  while (left <= right && top <= bottom)
  {
    for (size_t i = left; i <= right; ++i)
    {
      matrix[top * cols + i] -= decreaseValue;
      decreaseValue++;
      count++;
    }
    top++;
    for (size_t i = top; i <= bottom; ++i)
    {
      matrix[i * cols + right] -= decreaseValue;
      decreaseValue++;
      count++;
    }
    right--;
    if (top <= bottom)
    {
      for (size_t i = right; i >= left; --i)
      {
        matrix[bottom * cols + i] -= decreaseValue;
        decreaseValue++;
        count++;
      }
      bottom--;
    }
    if (left <= right)
    {
      for (size_t i = bottom; i >= top; --i)
      {
        matrix[i * cols + left] -= decreaseValue;
        decreaseValue++;
        count++;
      }
      left++;
    }
  }
  return;
}
