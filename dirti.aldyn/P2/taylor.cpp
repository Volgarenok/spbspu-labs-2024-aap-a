#include "taylor.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>

double dirti::arcsin_math(double x)
{
  return std::asin(x);
}

double dirti::e_math(double x)
{
  return std::exp(-1 * (x * x));
}

double dirti::arcsin_taylor(double x, size_t k, double error)
{
  double result = x;
  double num = x;
  for (double i = 1.0; i < (k * 2.0 - 2.0); i += 2.0)
  {
    num *= (i / (i + 1)) * (i / (i + 2)) * pow(x, 2.0);
    result += num;
  }
  if (std::abs(result) - std::abs(arcsin_math(x)) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double dirti::e_taylor(double x, size_t k, double error)
{
  double result = 1.0;
  double num = 1.0;
  double factorial = 1.0;
  for (size_t i = 1; i < k; ++i)
  {
    num = num * x * x * (-1);
    factorial *= i;
    result += (num/factorial);
  }
  if (num > error)
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
    std::cout << std::fixed << std::setprecision(3) << std::setw(scnd) << dirti::e_taylor(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(scnd) << "<MATH_ERROR>";
  }
  std::cout << " ";
  std::cout << std::fixed << std::setprecision(3) << std::setw(oth) << dirti::e_math(x);
  std::cout << " ";
  try
  {
    std::cout << std::fixed << std::setprecision(3) << std::setw(scnd) << dirti::arcsin_taylor(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(scnd) << "<MATH_ERROR>";
  }
  std::cout << " ";
  std::cout << std::fixed << std::setprecision(3) << std::setw(oth) << dirti::arcsin_math(x);
}
