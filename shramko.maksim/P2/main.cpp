#include <iostream>

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;

  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Input error\n";
    return 1;
  }
}
