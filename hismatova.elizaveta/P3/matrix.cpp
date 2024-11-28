#include "matrix.h"
#include <iostream>

std::istream & hismatova::input_matrix(std::istream & in, int * matrix, size_t m, size_t n, size_t & read)
{
  read = 0;
  for (size_t i = 0; i < (m * n); ++i)
  {
    if (!(in >> matrix[i]))
    {
      break;
    }
    ++read;
  }
  return in;
}

int hismatova::find_longest(const int* matrix, size_t m, size_t n)
{
  int ans = 0;
  int count = 1;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      count = 1;
      size_t vr = j + 1;
      while (vr < n && matrix[i * n + vr] == matrix[i * n + j])
      {
        count++;
        vr++;
      }
      if (count > ans)
      {
        ans = count;
      }
    }
  }
  return ans;
}
