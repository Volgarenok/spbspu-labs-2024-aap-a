#include <iostream>
#include <cstring>
#include "output.h"
#include "uno_div_cube.h"

namespace mozhegova
{
  double uno_div_cube(double x, size_t k, double error);
  double uno_div_cube_cmath(double x);
  void output_row(double i, size_t k, double error);
  void output_table(double left, double right, size_t k, double step, double error);
}

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  const double step = 0.05;
  const double error = 0.001;

  mozhegova::output_table(left, right, k, step, error);
}