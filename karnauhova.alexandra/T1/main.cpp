#include <string>
#include <iostream>
#include "input.hpp"
#include "output.hpp"
#include "shape.hpp"
#include "check.hpp"
using namespace karnauhova;
int main()
{
  size_t count_error = 0;
  size_t c_shape = 0;
  point_t point {0,0};
  double k = 0;
  Shape* shaps[10000] = {};
  if (fabric_input(std::cin, shaps, count_error, point, k, c_shape))
  {
    return 1;
  }
  if (count_error > 0)
  {
    std::cerr << "Error in input!\n";
  }
  output(std::cout, shaps, point, k, c_shape);
}
