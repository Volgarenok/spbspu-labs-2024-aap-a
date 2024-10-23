#include <iostream>
#include <stdexcept>

double f(double x, size_t k, double error);

double f(double x, size_t k, double error)
{
  double next = cos(x);
  double result = 0.0;
  for (int i = 1; i < k; ++i)
  {
    result *= (-x * x) / ((2 * i - 1) * (2 * i));
    next += result;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return next;
}

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  const double error = 0.01;
  const double step = 0.123;
  for (auto i = left; i < right; i += step)
  {
    std::cout << i;
    std::cout << " ";
    try 
    {
      std::cout << f(right, k, error);
    }
    catch (std::logic_error & e)
    {
      std::cout << e.what();
    }
  }
}
