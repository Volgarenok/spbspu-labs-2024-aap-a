#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomaniq>
#include <cstring>

namespace karnauhova
{
  double f(double x, size_t k, double error);
  double stdf(double x);
}

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> k;
  
  const double error = 0.001;
  const double step = 0.05;
  const char * errorm = "<MATH ERROR>"
  size_t width = std::strlen(errorm);
  for (auto i = left; i < right; i += step)
  {
  //вывод
  }
  //вывод
  
}
double karnauhova::f(double x, size_t k, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i<k;++i)
  {
  //последовательностть сумма
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
double karnauhova::stdf(double)
{
  return 0.0
}
