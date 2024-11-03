#include "matrix.h"

#include <iostream>
#include <fstream>

hismatova::std::istream & input_matrix(std::istream & in, int * matrix, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    in >> matrix[i];
    ++read;
  }
  return in;
}

void hismatova::output_matrix(std::ostream & out, int * matrix, size_t m, size_t n)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    out << matrix[i] << " ";
  }
}

int hismatova::find_longest(int * matrix, size_t m, size_t n)
{
  int ans = 0;
  int count = 1;
  int vr = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      vr = j + 1;
      while (vr < n && matrix[vr][i] == matrix[j][i]) 
      {
        count++;
      }
      if (count < vr - j)
      {
        count = vr - j;
        ans = i;
      }
    }
  }
  return ans;
}

bool hismatova::is_digit(char c)
{
  if (c >= "0" && c <= "9") {
    return true;
  }
  return false;
}
