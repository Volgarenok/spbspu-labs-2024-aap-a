#include "taylor.hpp"

void row(double x, double value)
{
  std::cout << x << " ";
  std::cout << value << " " << sveshnikov::math(x) << "\n";
}