#include "matrix.h"
#include <istream>
#include <cstddef>
void bocharov::output_matrix(std::ostream & out, const int * matrix, size_t rows, size_t cols)
{
  out << rows << " " << cols;
  for (size_t i = 0; i < (rows * cols); i++)
  {
    out << " " << matrix[i];
  }
  out << "\n";
}
