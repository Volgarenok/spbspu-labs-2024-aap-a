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
  constexpr double step = 0.2;
  constexpr double error = 0.001;
  for (double i = left; i < right; i += step)
  {
    evstyunichev::output(i, k, error);
    std::cout << "\n";
  }
  evstyunichev::output(right, k, error);
  std::cout << "\n";
  return 0;
}
