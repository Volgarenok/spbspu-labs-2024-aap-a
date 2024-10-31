#include "taylor.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>

void sveshnikov::row(double x, size_t k, double error)
{
  const char *errormsg = "<MATH ERROR>";
  const size_t sec_col_w = std::strlen(errormsg);
  std::cout << std::fixed;
  std::cout << std::setw(sec_col_w) << std::setprecision(2) << x;
  std::cout << " ";
  try
  {
    std::cout << std::setw(sec_col_w) << std::setprecision(8) << sveshnikov::taylor(x, k, error);
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(sec_col_w) << "<MATH ERROR>";
  }
  std::cout << " ";
  std::cout << std::setw(sec_col_w) << std::setprecision(8) << sveshnikov::math(x);
  std::cout << std::defaultfloat;
}
