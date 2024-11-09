#include "taylor_functions.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>

double dirti::math(double x)
{
  return std::asin(x);
}

double dirti::taylor(double x, size_t k, double error)
{
  double result = x;
  double num = x;
  for (double i = 1.0; i < (k * 2.0 - 2.0); i += 2.0)
  {
    num *= (i / (i + 1)) * (i / (i + 2)) * pow(x, 2.0);
    result += num;
  }
  if (!(result <= math(x) + error && result >= math(x) - error))
  {
    throw std::logic_error("math-error");
  }
  return result;
}

void dirti::output(double x, size_t k, double error)
{
  const char * errormsg = "<MATH_ERROR>";
  const size_t scnd = std::strlen(errormsg);
  const size_t oth = 10;
  std::cout << std::fixed << std::setprecision(2) << std::setw(oth) << x;
  std::cout << " ";
  try
  {
    std::cout << std::fixed << std::setprecision(3) << std::setw(scnd) << dirti::taylor(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(scnd) << "<MATH_ERROR>";
  }
  std::cout << " ";
  std::cout << std::fixed << std::setprecision(3) << std::setw(oth) << dirti::math(x);
  std::cout << "\n";
}
