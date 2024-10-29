#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include "taylor.hpp"

double taylor::DoTaylor(double x, size_t k, double error)
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

void taylor::PrintStringTaylor(double current, size_t k)
{
  std::cout << std::fixed;
  std::cout << std::setw(20) << current;
  try
  {
    std::cout << std::setw(20) << std::setprecision(6) << taylor::DoTaylor(current, k, taylor::error);
    std::cout << std::setw(20) << std::setprecision(6) << atan(current);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(20) << "MATH ERROR";
  };
  std::cout << "\n";
}

void taylor::PrintTableForTaylor(double left, double right, size_t k)
{
  for (double i = left; i < (right-taylor::step); i+=taylor::step)
  {
    taylor::PrintStringTaylor(i,k);
  };
  taylor::PrintStringTaylor(right,k);
}
