#include "taylor.hpp"

void row(double x, size_t k, double error)
{
  std::cout << x << " ";
  try
  {
    std::cout << sveshnikov::taylor(x, k, error);
  }
  catch (const std::logic_error &e)
  {
    std::cout << "MATH ERROR";
  }
  std::cout << " " << sveshnikov::math(x) << "\n";
}