#include "computingFunctions.hpp"

double krylov::f(double x, size_t k, double error)
{
  double result = 1;
  double previous_term = 1;
  double current_term = 0;
  int previous_factorial_value = 1;
  for (size_t i = 1; i < k; i++)
  {
    int factorial = 1;
    previous_term *= factorial;
    for (int j = 1; j <= previous_factorial_value + 2; j += 1)
    {
      factorial *= j;
    }
    previous_factorial_value += 2;
    current_term = (previous_term * x * x) / factorial;
    if (i % 2 == 0)
    {
      result += current_term;
      previous_term = current_term;
    }
    else
    {
      result -= current_term;
      previous_term = current_term;
    }
  }
  if (std::abs(previous_term) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double krylov::sinx_div_x(double x)
{
  return sin(x) / x;
}
