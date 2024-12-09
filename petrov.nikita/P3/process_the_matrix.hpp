#ifndef PROCESS_THE_MATRIX_HPP
#define PROCESS_THE_MATRIX_HPP
#include <fstream>

namespace petrov
{
  std::istream & inputMatrix(std::istream & in, int * ptr_matrix, size_t number_of_rows, size_t rows_length);
  size_t countNotZeroDiagonals(const int * ptr_matrix, const size_t number_of_rows, const size_t rows_length);
}
#endif

