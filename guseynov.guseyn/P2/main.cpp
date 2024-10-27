#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <cstring>

namespace taylor
{
  const double error = 0.001;
  const double step = 0.05;
  double f_taylor(double x, size_t k, double error);
  void table_for_taylor(double left, double right, size_t k);
}

int main()
{
  double left = 0.0;
  double right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if ((!std::cin) or (left < (-1.0)) or (right > 1.0))
  {
    return 1;
  };
  taylor::table_for_taylor(left, right, k);
  return 0;
}

double taylor::f_taylor(double x, size_t k, double error)
{
  double current = x;
  double result = x;
  double sign = -1;
  double divider = 3;
  for (size_t j{1}; j < k; j++)
  {
    current*=x*x;
    result+=current*sign/divider;
    divider+=2;
    sign*=-1;
  };
  if (std::abs(current*sign*(-1)/(divider-2)) > error)
  {
    throw std::logic_error("math error");
  };
  return result;
}

void taylor::table_for_taylor(double left, double right, size_t k)
{
  for (double i = left; i < right; i+=taylor::step)
  {
    std::cout << std::setw(20) << i;
    try
    {
      std::cout << std::setw(20) << taylor::f_taylor(i, k, taylor::error);
      std::cout << std::setw(20) << atan(i);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(20) << "MATH ERROR";
    };
    std::cout << "\n";
  };
}
