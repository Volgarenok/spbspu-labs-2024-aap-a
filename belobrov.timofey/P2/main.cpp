#include <iostream>
#include "output.hpp"

int main()
{
  using namespace belobrov;

  double left = 0;
  double right = 0;
  size_t k = 0;
  std::cin >> left >> right >> k;

  if (!std::cin)
  {
    std::cerr << "Bad input!" << "\n";
    return 1;
  }
  if (left > right)
  {
    std::cerr << "Logic error!" << "\n";
    return 1;
  }
  if ((left < -1 || left > 1) || (right < -1 || right > 1))
  {
    std::cerr << "Out of range!" << "\n";
    return 1;
  }

  output(left, right, 0.05, k);
  std::cout << "\n";
  return 0;
}


