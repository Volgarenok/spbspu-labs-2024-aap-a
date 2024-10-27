#include <iostream>

int main()
{
  double left = 0.0;
  double right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if ((!std::cin) or (left < (-1.0)) or (right > 1.0))
{
    return 1;
}
}

