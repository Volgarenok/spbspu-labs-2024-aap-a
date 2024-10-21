#include <iostream>
#include <cstring>
#include "declarations.hpp"

int main()
{
  double left = 0.0;
  double right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Wrong input!\n";
    return 1;
  }
  if (k<=0 || left > right || left <= -1 || right >= 1)
  {
    std::cerr << "Wrong input!\n";
    return 1;
  }
  const double error = 0.001;
  const double step = 0.05;
  for (auto i = left; i < right; i += step)
  {
    abramov::str_of_table(i, k, error);
  }
  abramov::str_of_table(right, k, error);
}
