#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
#include <cstddef>
namespace bocharov
{
  std:: istream & input_matrix(std::istream & in, int * const t, size_t m, size_t n);
  void  output_matrix(std::ostream & out, const int * const t, size_t m, size_t n);
  void check_argc(int argc);
  long int check_number(const char * const argv1);
  void matrix_replace(int * const t, size_t m, size_t n);
}
#endif
