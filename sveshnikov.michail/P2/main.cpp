#include "taylor.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "ERROR: the input could not be recognized\n";
    return 1;
  }
  const double error = 0.002;
  const double step = 0.06;

  for (auto i = left; i < right; i += step)
  {
    double value = sveshnikov::taylor(i, k, error);
    sveshnikov::row(i, value);
  }
}

