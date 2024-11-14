#include <iostream>
#include "output.hpp"

int main()
{
  using namespace belobrov;

  double left = 0;
  double right = 0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  constexpr double step = 0.05;
  constexpr double error = 0.01;

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

  output(left, right, step, k, error);
  std::cout << "\n";
}


