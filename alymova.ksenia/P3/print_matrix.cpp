#include "matrix.h"
#include <istream>
#include <cstddef>
void alymova::print_matrix(std::ostream& output, const int* const matrix, size_t rows, size_t cols)
{
  output << rows << " " << cols;
  if (rows != 0 && cols != 0)
  {
    for (size_t i = 0; i < rows * cols; i++)
    {
      output << " " << matrix[i];
    }
  }
}
