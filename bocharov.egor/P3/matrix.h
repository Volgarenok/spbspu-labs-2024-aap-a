#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
#include <cstddef>
namespace bocharov
{
  std:: istream & input_matrix(std::istream & in, int * matrix, size_t rows, size_t cols, size_t & read);
  void output_matrix(std::ostream & out, const int * matrix, size_t rows, size_t cols);
  void change_matrix(int * matrix, size_t rows, size_t cols);
  void check_argc(int argc);
  long int check_number(const char * argv1);
  size_t find_local_maximum(const int * matrix, size_t rows, size_t cols);
}
#endif
