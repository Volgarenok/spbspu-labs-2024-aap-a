#include "taylor.h"
#include <iostream>
#include <stdexcept>

void demehin::output(double x, const size_t k, const double error)
{
  std::cout << x << " ";
  try
  {
    std::cout << demehin::f(x, k, error);
  }
  catch(const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << " " << demehin::stdf(x) << "\n";
}
