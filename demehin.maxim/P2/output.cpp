#include "taylor.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

void demehin::output(double x, const size_t k, const double error)
{
  constexpr size_t column_width = 15;
  constexpr size_t c = column_width;
  std::cout << std::setw(c);
  std::cout << x << " ";
  try
  {
    std::cout << std::setw(c);
    std::cout << demehin::f(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << std::setw(c);
  std::cout << " " << demehin::stdf(x) << "\n";
}
