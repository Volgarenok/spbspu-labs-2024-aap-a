#include "matrix.hpp"
#include <fstream>
#include <sstream>
#include <limits>
std::istream &sharifullina::inputMatrix(std::istream &in, int * t,
    size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < m * n; i++)
  {
    in >> t[i];
    read++;
  }
  return in;
}
size_t sharifullina::countLocMax(const int * t, size_t m, size_t n)
{
  size_t k = 0;
  for (size_t i = 1; i < m - 1; i++)
  {
    for (size_t j = 1; j < n - 1; j++)
    {
      int current = t[i][j]
      if (current > t[i - 1][j] && current > t[i + 1][j] &&
      current > t[i][j - 1] && current > t[i][j + 1])
      {
        k++;
      }
    }
  }
  return k;
}
int sharifullina::countMaxSumMdg(const int * t, size_t m, size_t n)
{
  int maxSum = std::numeric_limits<int>::min();
    for (size_t col = n - 1; col >= 0; --col)
    {
      int sum = 0;
      size_t startCol = col;
      size_t startRow = 0;
      while (startCol < n && startRow < m)
      {
        sum += t[startRow][startCol];
        startCol++;
        startRow++;
      }
      maxSum = std::max(maxSum, sum);
    }
    for (int row = 1; row < m; ++row)
    {
      int sum = 0;
      size_t startRow = row;
      size_t startCol = 0;
      while (startRow < m && startCol < n)
      {
        sum += t[startRow][startCol];
        startRow++;
        startCol++;
      }
      maxSum = std::max(maxSum, sum);
    }
    return maxSum;
}
