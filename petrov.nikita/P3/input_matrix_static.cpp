#include "process_the_matrix.hpp"
#include <fstream>

std::ifstream & petrov::input_matrix_static(std::ifstream & in, int * ptr_matrix, size_t number_of_rows, size_t rows)
{
  for (size_t i = 0; i < number_of_rows * rows; i++)
  {
    in >> ptr_matrix[i];
  }
  return in;
}