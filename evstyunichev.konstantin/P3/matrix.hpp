#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
namespace evstyunichev
{
  int cast_to_digit(const char *);
  std::istream & input(std::istream &, int *, size_t, size_t, size_t &);
  bool is_row_nsm(const int *, size_t, size_t);
  size_t cnt_rows_nsm(const int *, size_t, size_t);
  bool solve_print(std::istream &, std::ostream &, int *, size_t, size_t, size_t &);
  void output(std::ostream &, const int *, size_t, size_t);
}
#endif
