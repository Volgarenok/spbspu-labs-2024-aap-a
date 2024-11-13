#ifndef PROCESS_THE_MATRIX_HPP
#define PROCESS_THE_MATRIX_HPP
#include <fstream>

namespace petrov
{
  int check_arguments(int argc, const char ** argv);
  std::istream & input_matrix(std::istream & in, int * ptr_matrix, size_t number_of_rows, size_t rows_length);
  int process_matrix_data(int * ptr_matrix, size_t number_of_rows, size_t rows_length);
}
#endif

