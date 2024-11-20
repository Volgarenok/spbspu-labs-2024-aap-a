#include "process_the_matrix.hpp"
#include <fstream>

std::istream & petrov::inputMatrix(std::istream & in, int * ptr_matrix, size_t number_of_rows, size_t rows_length)
{
  for (size_t i = 0; i < (number_of_rows * rows_length); i++)
  {
    in >> ptr_matrix[i];
  }
  return in;
}

