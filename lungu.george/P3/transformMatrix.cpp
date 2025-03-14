#include "lungu.h"

namespace lungu
{
  void transformMatrix(int *matrix, int rows, int cols)
  {
    int value = 1;
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right)
    {
      for (int i = left; i <= right; ++i)
      {
        matrix[bottom * cols + i] += value++;
      }
      bottom--;
      for (int i = bottom; i >= top; --i)
      {
        matrix[i * cols + right] += value++;
      }
      right--;
      if (top <= bottom)
      {
        for (int i = right; i >= left; --i)
        {
          matrix[top * cols + i] += value++;
        }
        top++;
      }
      if (left <= right)
      {
        for (int i = top; i <= bottom; ++i)
        {
          matrix[i * cols + left] += value++;
        }
        left++;
      }
    }
  }
}
