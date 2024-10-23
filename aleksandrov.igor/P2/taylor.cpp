#include <stdexcept>

double taylor(double x, size_t k, double error)
{
  double next = 1.0;
  double result = next;
  for (size_t i = 0; i < k; ++i)
  {
    next *= -x*x / (2*(i+1)*(2*(i+1)+1));
    if (std::abs(next) < error)
    {
      throw std::logic_error("math-error");
    }
    result += next;
  }
  return result;
}


