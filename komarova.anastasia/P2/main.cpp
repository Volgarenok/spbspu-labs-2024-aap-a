#include <iostream>
#include <cstddef>
#include <cmath>
#include <stdexcept>
#include "kola.h"

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
  if ((left <= -1.0) or (left >= 1.0))
  {
    std::cerr << "incorrect left \n";
    return 1;
  }
  if ((right >= 1.0) or (right <= -1.0))
  {
    std::cerr << "incorrect right \n";
    return 1;
  }
  if (right < left)
  {
    std::cerr << "incorrect right and left \n";
    return 1;
  }

  const double error = 0.001;
  const double step = 0.02;

  for (auto i = left; i < right; i += step)
  {
    double y = komarova::ln_Teilor(i);
    try
    {
      double value = komarova::Teilor(i, k, error);
      komarova::output(i, value, y);
    }
    catch (const std::logic_error & e)
    {
      komarova::matherr(i, y);
    }
  }
  double g = komarova::ln_Teilor(right);
  try
  {
    double value = komarova::Teilor(right, k, error);
    komarova::output(right, value, g);
  }
  catch (const std::logic_error & e)
  {
    komarova::matherr(right, g);
  }
}
