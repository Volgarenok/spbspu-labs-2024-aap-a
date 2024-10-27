#include <iostream>
#include <cmath>

int main()
{
  double left = 0.0, right = 0.0;
  size-t k = 0;
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
    try
    {
      double value = komarova::Teilor(i, k, error);
      komarova::output(i, value, komarova::ln_Teilor(i));
    }
    catch (const std::logic_error & e)
    {
      void komarova::matherr(i, value, komarova::ln_Teilor(i))
    }
  }
  try
  {
    double value = komarova::Teilor(right, k, error);
    komarova::output(right, value, komarova::ln_Teilor(right));
  }
  catch (const std::logic_error & e)
  {
    void komarova::matherr(right, value, komarova::ln_Teilor(right))
  }
}
