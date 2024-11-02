#include "inputMtrx.hpp"

std::istream & shramko::matrixInput(std::istream & in, int* mtrx, size_t count_rows, size_t count_columns)
{
  for (size_t i = 0; i < (count_rows * count_coloumns); ++i)
  {
    in >> matrix[i];
  }
  return in;
}
