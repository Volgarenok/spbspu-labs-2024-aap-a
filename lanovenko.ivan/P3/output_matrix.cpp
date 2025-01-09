#include "output_matrix.h"

void lanovenko::outputMatrix(std::ostream& output, const int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    output << matrix[i * rows];
    for (size_t j = 1; j < cols; j++)
    {
      output << ' ' << matrix[i * cols + j];
    }
    output << '\n';
  }
}
