#include "taylorCalc.hpp"
#include <iomanip>
#include <cstring>
#include <iostream>
#include <cmath>

double shabalin::taylorViaCos(double x, size_t k, double error)
{
  double current_term = x;
  double result = 0.0;
  for (size_t i = 1; i < k; ++i)
  {
    current_term *= -x * x / (2 * i) * (2 * i - 1);
    result += current_term;
  }
  if (std::abs(result) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

void shabalin::output(double x, size_t k, double error)
{
  constexpr size_t clmn = 10;
  std::cout << std::setw(clmn) << x;
  std::cout << " ";
  try
  {
    std::cout << std::setw(clmn) << shabalin::taylorViaCos(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(clmn) << e.what();
  }
  std::cout << std::setw(clmn) << std::cos(x);
}

void shabalin::finalOutput(double left, double right, double step, size_t k, double error)
{
  for (auto i = left; i < right; i += step)
  {
    shabalin::output(i, k, error);
    std::cout << "\n";
  }
  shabalin::output(right, k, error);
  std::cout << "\n";
}
