#include <iostream>

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "The input could not be recognized\n";
    return 1;
  }
  if (left > right)
  {
    std::cerr << "The interval is set incorrectly\n";
    return 1;
  }
  if ((-1 < left && left < 1) &&
      (-1 < right && right < 1))
  {
    std::cerr << "The interval is not in the definition area\n";
    return 1;
  }
}