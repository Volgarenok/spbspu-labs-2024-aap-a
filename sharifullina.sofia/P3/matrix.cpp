#include "matrix.hpp"
#include <fstream>
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
bool sharifullina::isLocMax(const int * t, size_t n, size_t i, size_t j)
{
  for (int di = -1; di <= 1; ++di)
  {
    for (int dj = -1; dj <= 1; ++dj)
    {
      if (di == 0 && dj == 0) continue;
      size_t ni = i + di;
      size_t nj = j + dj;
      if (ni < n && nj < n)
      {
        if (t[i * n + j] <= t[ni * n + nj])
        {
          return false;
        }
      }
    }
  }
  return true;
}
size_t sharifullina::countLocMax(const int * t, size_t m, size_t n)
{
  size_t k = 0;
  for (size_t i = 1; i < m - 1; i++)
  {
    for (size_t j = 1; j < n - 1; j++)
    {
      if (isLocMax(t, n, i, j))
      {
        k++;
      }
    }
  }
  return k;
}
int sharifullina::countMaxSumMdg(const int * t, size_t m, size_t n)
{
  int maxSum = std::numeric_limits< int >::min();
  for (size_t col = n - 1; col < n; --col)
  {
    int sum = 0;
    size_t startCol = col;
    size_t startRow = 0;
    while (startCol < n && startRow < m)
    {
      sum += t[startRow * n + startCol];
      startCol++;
      startRow++;
    }
    maxSum = std::max(maxSum, sum);
  }
  for (size_t row = 1; row < m; ++row)
  {
    int sum = 0;
    size_t startRow = row;
    size_t startCol = 0;
    while (startRow < m && startCol < n)
    {
      sum += t[startRow * n + startCol];
      startRow++;
      startCol++;
    }
    maxSum = std::max(maxSum, sum);
  }
  return maxSum;
}
