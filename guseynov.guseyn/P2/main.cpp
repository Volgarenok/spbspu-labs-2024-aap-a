#include <iostream>
#include "taylor.hpp"

int main()
{
  double left = 0.0;
  double right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if ((!std::cin) or (left < (-1)) or (right > 1) or (k > 10) or (left > right))
  {
    return 1;
  };
  taylor::PrintTableForTaylor(left, right, k);
  return 0;
}
