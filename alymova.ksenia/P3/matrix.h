#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <istream>
namespace alymova
{
  int alymova::check_size(size_t rows, size_t cols);
  std::istream& input_matrix(std::istream& input, int* const matrix, size_t& rows, size_t& cols);
  void print_matrix(std::ostream& output, const int* const matrix, size_t rows, size_t cols);
  void change_matrix(int* const matrix, size_t rows, size_t cols);
  
}
#endif
