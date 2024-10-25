#include <iostream>
#include "output.hpp"

int main()
{
  using namespace belobrov;

  double left = 0, right = 0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "pupupuuuu... bad input!" << "\n";
    return 1;
  }
  if (left > right)
  {
    std::cerr << "pupupuuuu... logic?" << "\n";
    return 1;
  }
  if ((left < -1 || left > 1) || (right < -1 || right > 1))
  {
    std::cerr << "pupupuuuu... mimo!" << "\n";
    return 1;
  }

  output(left, right, 0.05, k);

}


