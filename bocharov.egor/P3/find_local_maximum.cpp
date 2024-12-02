#include "matrix.h"
size_t bocharov::find_local_maximum(const int * matrix, size_t rows, size_t cols)
{
  size_t result = 0;
  for (size_t i = 1; i < rows - 1; i++)
  {
    for (size_t j = 1; j < cols - 1; j++)
    {
      size_t number = i * cols + j;
      int current = matrix[number];
      int left = matrix[number - 1];
      int right = matrix[number + 1];
      int up = matrix[number - cols];
      int down = matrix[number + cols];
      int diagonalupleft = matrix[number - cols - 1];
      int diagonalupright = matrix[number - cols + 1];
      int diagonaldownleft = matrix[number + cols - 1];
      int diagonaldownright = matrix[number + cols + 1];
      bool localmax = (current > left) && (current > right);
      localmax = localmax && ((current > up) && (current < down));
      localmax = localmax && ((current > diagonalupleft) && (current > diagonalupright));
      localmax = localmax && ((current > diagonaldownleft) && (current > diagonaldownright));
      if (localmax)
      {
        result++;
      }
    }
  }
  return result;
}
