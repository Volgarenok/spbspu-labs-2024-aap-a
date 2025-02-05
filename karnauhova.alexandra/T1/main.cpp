#include <string>
#include <iostream>
#include "input.hpp"
#include "output.hpp"
#include "shape.hpp"
#include "compositeShape.hpp"
int main()
{
  using namespace karnauhova;
  size_t count_error = 0;
  point_t point {0,0};
  double k = 0;
  CompositeShape shaps(1);
  try
  {
    input(std::cin, shaps, count_error, point, k);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memmory\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    return 1;
  }
  if (count_error > 0)
  {
    std::cerr << "Error in input!\n";
  }
  output(std::cout, shaps, point, k);
}

