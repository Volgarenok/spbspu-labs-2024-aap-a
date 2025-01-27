#include <string>
#include <iostream>
#include "input.hpp"
#include "output.hpp"
#include "shape.hpp"
#include "check.hpp"
void delet(karnauhova::Shape** shaps, size_t c_shape);
using namespace karnauhova;
int main()
{
  size_t count_error = 0;
  size_t c_shape = 0;
  point_t point {0,0};
  double k = 0;
  Shape* shaps[10000] = {};
  try
  {
    if (fabric_input(std::cin, shaps, count_error, point, k, c_shape))
    {
      delet(shaps, c_shape);
      return 1;
    }
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memmory\n";
    delet(shaps, c_shape);
    return 1;
  }
  if (count_error > 0)
  {
    std::cerr << "Error in input!\n";
  }
  output(std::cout, shaps, point, k, c_shape);
  delet(shaps, c_shape);
}

void delet(Shape** shaps, size_t c_shape)
{
  for (size_t i = 0; i < c_shape; i++)
  {
    delete shaps[i];
  }
}
