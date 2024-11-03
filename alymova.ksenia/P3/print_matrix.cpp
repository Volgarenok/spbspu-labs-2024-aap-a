#include "matrix.h"
#include <istream>
#include <cstddef>
void alymova::print_matrix(std::ostream& output, const int* const matrix, size_t read)
{
  output << matrix[0];
  for (size_t i = 1; i < read; i++)
  {
    output << " " << matrix[i];
  }
}
