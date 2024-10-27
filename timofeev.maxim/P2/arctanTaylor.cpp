#include <iostream>
#include "arctanTaylor.h"
#include <stdexcept>
double timofeev::arctanTaylor(double x, double absError, size_t numberMax) {
  double term = x;
  double sum = term;
  double xPower = x;
  for (size_t n = 1; n < numberMax; n ++)
  {
    xPower *= x * x;
    term = (xPower / (2 * n + 1)) * ((n % 2 == 0) ? 1 : -1);
    sum += term;
    if (std::abs(term) <= absError){
      return sum;
    }
  }
  throw std::logic_error("math error");
}
