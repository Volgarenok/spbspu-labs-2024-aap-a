#include <iostream>
#include <cstring>
#include "output.h"
#include "uno_div_cube.h"

namespace mozhegova
{
  double uno_div_cube(double x, size_t k, double error);
  double uno_div_cube_cmath(double x);
  void output_row(auto i);
  void output_table(double left, double right, size_t k);
}

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;

  const double error = 0.001;
  const double step = 0.05;
  const size_t SecColWidth = std::strlen("<MATH ERROR>") + 2;
  const size_t OtherCol = 8;

  output_table(left, right, k);
}