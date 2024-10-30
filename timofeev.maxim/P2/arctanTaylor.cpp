#include "arctanTaylor.h"
#include <iostream>
#include <stdexcept>
double timofeev::arctan_taylor(double x, double abs_error, size_t number_max)
{
  double term = x;
  double sum = term;
  double xPower = x;
  for (size_t n = 1; n < number_max; n ++)
  {
    xPower *= x * x;
    term = (xPower / (2 * n + 1)) * ((n % 2 == 0) ? 1 : -1);
    sum += term;
    if (std::abs(term) <= abs_error)
    {
      return sum;
    }
  }
  throw std::logic_error("math error");
}
