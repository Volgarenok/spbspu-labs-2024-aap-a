#include <iostream>
#include "tableMaker.hpp"

int main()
{
  using namespace maslovskiy;

  double left = 0, right = 0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  const double error = default_error;
  if (!std::cin)
  {
    std::cerr << "Bad input" << "\n";
    return 1;
  }
  if (left > right)
  {
    std::cerr << "Logic error" << "\n";
    return 1;
  }
  if ((left < -1 || left > 1) || (right < -1 || right > 1))
  {
    std::cerr << "Out of range Error" << "\n";
    return 1;
  }

  tableMaker(left, right, 0.05, k, error);
  std::cout << "\n";
}

