#include "taylorPolynomial.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>

void abramov::str_of_table(double x, size_t k, double error)
{
  constexpr const char *errmsg = "<MATH_ERROR>";
  constexpr size_t second_column_width = std::strlen(errmsg);
  const size_t other_columns_width = 10;
  size_t sec_w = second_column_width;
  size_t oth_w = other_columns_width;
  std::cout << std::setw(oth_w) << x << " ";
  try
  {
    std::cout << std::setw(sec_w) << abramov::f(x, k, error);
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(sec_w) << e.what();
  }
  std::cout << " " << std::setw(oth_w) << abramov::exp_x(x);
}
