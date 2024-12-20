#include <cstddef>
#include <iostream>
#include "shape.hpp"
#include "createShape.hpp"

int main()
{
  constexpr size_t size = 10000;
  shramko::Shape* shapes[size] = {};
  int count = 0;
  count = shramko::createShape(std::cin, std::cerr, std::cout, shapes);

  if (count == -1)
  {
    return 1;
  }
  shramko::clear(shapes, count);
}
