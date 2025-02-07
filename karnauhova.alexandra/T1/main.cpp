#include <string>
#include <iostream>
#include "input.hpp"
#include "output.hpp"
#include "shape.hpp"
#include "compositeShape.hpp"
int main()
{
  using namespace karnauhova;
  point_t point {0,0};
  double k = 0;
  CompositeShape shaps(1);
  try
  {
    input(std::cin, shaps, point, k);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memmory\n";
    return 1;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error in input!\n";
  }
  catch (const std::logic_error & e)
  {
    return 1;
  }
  output(std::cout, shaps, point, k);
}

