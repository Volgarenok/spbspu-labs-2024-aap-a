#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <cstring>

double f(double x, size_t k, double error);

double f(double x, size_t k, double error)
{
  double current_term = x;
  double result = 0.0;
  for (int i = 1; i < k; ++i)
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

double stdf(double x)
{
  return std::cos(x);
}

void output(double x, size_t k, double error, size_t clmn)
{
  std::cout << std::setw(clmn) << x;
  std::cout << " ";
  try
  {
    std::cout << std::setw(clmn) << f(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(clmn) << e.what();
  }
  std::cout << std::setw(clmn) << stdf(x) << "\n";
}

void finalOutput(double left, double right, double step, size_t k, double error, size_t clmn)
{
   for (auto i = left; i < right; i += step)
  {
    output(i, k, error, clmn);
  }
  output(right, k, error, clmn);
}

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin.good())
  {
    std::cerr << "Input error" << "\n";
    return 1;
  }
  if ((left > right) or (left < -1) or (right > 1))
  {
    std::cerr << "Incorrect input";
    return 1;
  }
  const double error = 0.01;
  const double step = 0.123;
  finalOutput(left, right, step, k, error, 10);
}
