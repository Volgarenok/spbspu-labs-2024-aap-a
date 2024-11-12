#include "output_matrix.h"

int finaev::kol_loc_max(const int * matrix, size_t strk, size_t stl)
{
  int res = 0;
  for (size_t i = 0; i < strk; i++)
  {
    for (size_t j = 1; j < (stl - 1); j++)
    {
      if (matrix[i * strk + j - 1] < matrix[i * strk + j] && matrix[i * strk + j + 1] < matrix[i * strk + j])
      {
        res += 1;
      }
    }
  }
  return res;
}

void finaev::output_matrix(std::ostream & out, const int * matrix, size_t strk, size_t stl)
{
  int res = 0;
  res = kol_loc_max(matrix, strk, stl);
  out << res << "\n";
}
