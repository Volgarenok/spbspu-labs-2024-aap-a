#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>

namespace hismatova
{
  double f(double x, size_t k, double error);
  double stdf(double x);
}

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  const double error = 0.001;
  const double step = 0.05;
  const char * errormsg = "<MATH ERROR>";
  const size_t second_column_width = std::strlen(errormsg);
  const size_t others_columns = 10;
  for (auto i = left; i < right; i += step)
  {
    size_t oth = others_columns;
    std::cout << std::setw(oth) << i;
    std::cout << " ";
    size_t snd = second_column_width;
    try
    {
      std::cout << std::setw(snd) << hismatova::f(right, k, error);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(snd) << "<MATH ERROR>";
    }
    std::cout << std::setw(oth) << " " << hismatova::stdf(i);
    std::cout << "\n";
  }
  std::cout << right;
  try 
  {
    std::cout << " " << hismatova::f(right, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << " " << hismatova::stdf(right);
  std::cout << "\n";
}

double hismatova::f(double x, size_t k, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i < k; ++i)
  {
    next *= x;
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double hismatova::stdf(double)
{
  return 0.0;
}

