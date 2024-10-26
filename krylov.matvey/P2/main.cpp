#include <iostream>
#include <cmath>
namespace krylov
{
  double f(double x, size_t k, double error);
  double sinx_div_x(double x);
  void line_output(
}

int main()
{
  double left_border = 0.0, right_border = 0.0;
  size_t max_terms_number = 0;
  std::cin >> left_border >> right_border >> max_terms_number;
  if (!std::cin || (left_border < -1) || (right_border > 1))
  {
    std::cerr << "Incorrect input!\n";
    return 1;
  }
  const double error = 0.001;
  const double step = 0.01;
}

double f(double x, size_t k, double error)
{
  double result = 1;
  double previous_term = 1;
  double current_term = 0;
  int previous_factorial_value = 1;
  for  (i = 1; i < k; i++)
  {
    int factorial = 1;
    previous_term *= factorial;
    for (j = 1; j <= previous_factorial_value + 2; j+=1)
    {
      factorial *= j;
    }
    previous_factorial_value+=2;
    current_term = previous_term * x * x / factorial;
    if (i%2==0)
    {
      result += current_term;
      previous_term = current_term;
    }
    else
    {
      result -= current_term;
      previous_term = current_term;
    }
    return result;
  }
