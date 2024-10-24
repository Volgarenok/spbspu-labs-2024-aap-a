#include <iostream>
#include <cstring>
#include "output.hpp"
#include "uno_div_cube.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Not a number\n";
    return 1;
  }
  if (left  <= -1 || right >= 1 || right < left)
  {
    std::cerr << "Incorrect interval\n";
    return 1;
  }

  const double step = 0.05;
  const double error = 0.001;

  mozhegova::output_table(left, right, k, step, error);
}
