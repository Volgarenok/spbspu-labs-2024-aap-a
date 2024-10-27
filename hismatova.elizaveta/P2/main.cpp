#include "taylor.h"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin || left > right || right > 1 || left < -1)
  {
    std::cerr << "ERROR: wrong cin\n";
    return 1;
  }
  const double step = 0.05;
  for (double i = left; i < right; i += step)
  {
    hismatova::resultsInTable(i, k);
  }
  hismatova::resultsInTable(right, k);
}
