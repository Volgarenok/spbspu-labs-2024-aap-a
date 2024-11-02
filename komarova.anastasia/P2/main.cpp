#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "tableTeilor.h"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Input is incorrect \n";
    return 1;
  }
  if ((left <= -1.0) || (left >= 1.0))
  {
    std::cerr << "incorrect left \n";
    return 1;
  }
  if ((right >= 1.0) || (right <= -1.0))
  {
    std::cerr << "incorrect right \n";
    return 1;
  }
  if (right < left)
  {
    std::cerr << "incorrect right and left \n";
    return 1;
  }

  constexpr double error = 0.001;
  constexpr double step = 0.02;

  for (auto i = left; i < right; i += step)
  {
    double y = komarova::lnTeilor(i);
    try
    {
      double value = komarova::teilor(i, k, error);
      komarova::output(i, value, y);
    }
    catch (const std::logic_error & e)
    {
      komarova::matherr(i, y);
    }
  }
  double g = komarova::lnTeilor(right);
  try
  {
    double value = komarova::teilor(right, k, error);
    komarova::output(right, value, g);
  }
  catch (const std::logic_error & e)
  {
    komarova::matherr(right, g);
  }
}
