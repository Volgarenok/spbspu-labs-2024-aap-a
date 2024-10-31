#include <iostream>
#include "taylor_cos.hpp"
#include "taylor_output.hpp"
int main()
{
  constexpr double step = 0.1, absError = 0.001;
  double left = 0.0, right = 0.0;
  size_t numberMax = 0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin || right > 1 || left < -1 || left > right)
  {
    std::cerr << "ERROR: incorrect input" << "\n";
    return 1;
  }
  for (double x = left; x < right; x += step)
  {
    double stdval = nikonov::stdcos(x);
    try
    {
      double val = nikonov::cos(x, numberMax, absError);
      nikonov::stringOutput(x, val, stdval);
      std::cout << "\n";
    }
    catch (const std::logic_error& e)
    {
      nikonov::stringOutput(x, e, stdval);
      std::cout << "\n";
    }
  }
  double stdval = nikonov::stdcos(right);
  try
  {
    double val = nikonov::cos(right, numberMax, absError);
    nikonov::stringOutput(right, val, stdval);
    std::cout << "\n";
  }
  catch (const std::logic_error& e)
  {
    nikonov::stringOutput(right, e, stdval);
    std::cout << "\n";
  }
}
