#include <iostream>
#include <cmath>

namespace sharifullina
int  main()
{
  double  left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;

  if (!std::cin)
  {
    std::cerr << "Not a number\";
    return 1;
  }
  if (left <= -1 || right >= 1 || left > right)
  {
    std::cerr << "Incorrect interval\n";
    return 1;
  }

  const double error = 0.001;
  const double step = 0.05;
}
