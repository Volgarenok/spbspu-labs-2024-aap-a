#include "matrixFunc.h"
#include <fstream>

std::istream& averenkov::input_matrix(std::istream& in, int* t, size_t m, size_t n, size_t& read)
{
  read = 0;
  for (size_t i = 0; i < m * n; ++i)
  {
    if (in >> t[i])
    {
      ++read;
    }
  }
  return in;
}

size_t averenkov::num_col_lsr(int* t, size_t m, size_t n)
{
  size_t longest_id = 0;
  size_t longest = 0;
  for (size_t j = 0; j < n; ++j)
  {
    size_t now = 1;
    size_t max = 1;
    for (size_t i = 1; i < m; ++i)
    {
      if (t[i * n + j] == t[(i - 1) * n + j])
      {
        ++now;
      }
      else
      {
        now = 1;
      }
      if (now > max)
      {
        max = now;
      }
    }

    if (max > longest)
    {
      longest = max;
      longest_id = j;
    }
  }
  return longest_id;
}


void averenkov::output_matrix(std::ostream& out, int* t, size_t m, size_t n)
{
  for (size_t i = 0; i < m * n; ++i) {
    out << t[i] << " ";
  }
}
