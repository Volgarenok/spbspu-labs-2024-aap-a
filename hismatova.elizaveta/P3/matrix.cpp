#include "matrix.h"

#include <iostream>
#include <fstream>

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

void hismatova::output_result(std::ostream & out, int * matrix, size_t m, size_t n)
{
  out << hismatova::find_longest(matrix, m, n) << "\n";
}
int hismatova::find_longest(int * matrix, size_t m, size_t n){
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

bool hismatova::is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

