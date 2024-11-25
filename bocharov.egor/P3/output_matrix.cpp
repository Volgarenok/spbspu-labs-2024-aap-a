#include "matrix.h"
#include <istream>
#include <cstddef>
void bocharov::output_matrix(std::ostream & out, const int * matrix, size_t rows, size_t cols, size_t result)
{
  out << rows << " " << cols << " " << result;
  for (size_t i = 0; i < (rows * cols); i++)
  {
    out << " " << matrix[i];
  }
}
