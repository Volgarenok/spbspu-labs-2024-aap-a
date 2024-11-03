#ifndef PROCESS_THE_MATRIX_HPP
#define PROCESS_THE_MATRIX_HPP
#include <fstream>

namespace petrov
{
  std::ifstream & input_matrix_static(std::ifstream & in, int * ptr_matrix, size_t number_of_rows, size_t rows);
  std::ifstream & input_matrix_dynamic(std::ifstream & in);
}
#endif