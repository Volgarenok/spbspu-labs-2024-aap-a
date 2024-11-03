#ifndef PROCESS_THE_MATRIX_HPP
#define PROCESS_THE_MATRIX_HPP
#include <fstream>

namespace petrov
{
  int check_arguments(int argc, char ** argv);
  std::istream & input_matrix_static(std::istream & in, int * ptr_matrix, size_t number_of_rows, size_t rows);
  std::istream & input_matrix_dynamic(std::istream & in);
}
#endif