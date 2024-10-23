#include <iostream>
#include "taylor.hpp"
#include <cstddef>

int main()
{
  double left = 0.0, right = 0.0;
  size_t series = 0;
  std::cin >> left >> right >> series;
  if (!std::cin)
  {
    std::cerr << "ERROR WITH ENTER";
    return 1;
  }

  if ((left>right)||(left<=-1 || right>=1))
  {
    std::cerr << "ERROR WITH GAP";
    return 1;
  }

  const double error = 0.01;
  const double step = 0.02;

  for (auto x = left; x < right; x += step)
  {
   double value = dribas::taylor(x,series,error);
   std::cout << x;
   std::cout << " " << value;
   std::cout << " " << dribas::uno_div_cube(x);
   std::cout <<"\n";
  }
}
