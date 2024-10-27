#include <iostream>
#include "arcsin.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin || (left <= -1) || (right >= 1) || (left > right))
  {
    std::cerr << "input error\n";
    return 1;
  }
  const double step = 0.2;
  const double error = 0.001;

  for (double i = left; i < right; i += step)
  {
    kos::output(i, k, error);
    std::cout << "\n";
  }
  
  if (left != right)
  {
    kos::output(right, k, error);
    std::cout << "\n";
  }
  return 0;
}
