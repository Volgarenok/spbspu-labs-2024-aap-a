#include <iostream>
#include "taylor.h"

int main()
{
  constexpr double error = 0.042;
  constexpr double step = 0.05;
  double left = 0.0, right = 0.0;
  size_t max = 0;
  std::cout << "Enter the start,end of the calculation interval and maximum numbers:";
  std::cin >> left >> right >> max;
  if (std::cin.fail())
  {
    std::cerr << "Error. Wrong imput." << '\n';
    return 1;
  }
  if (max <= 0 || left <= -1.0 || right >= 1.0 || left > right)
  {
    std::cerr << "Error. Incorrect values." << '\n';
    return 1;
  }
  for (auto i = left; i < right; i += step)
  {
    ivanova::output(i, max, error);
    std::cout << '\n';
  }
  ivanova::output(right, max, error);
  std::cout << "\n";
}
