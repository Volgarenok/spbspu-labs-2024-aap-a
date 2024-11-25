#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
#include <cstddef>
namespace bocharov
{
  std:: istream & input_matrix(std::istream & in, int * const matrix, size_t rows, size_t cols, size_t & read);
  void  output_matrix(std::ostream & out, const int * const matrix, size_t rows, size_t cols, size_t result);
  void matrix_replace(int * const matrix, size_t rows, size_t cols);
  void check_argc(int argc);
  long int check_number(const char * const argv1);
  size_t NumLocMax(const int * matrix,size_t rows, size_t cols);
}
#endif
