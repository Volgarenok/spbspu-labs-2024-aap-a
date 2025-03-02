#include <cstddef>
#include <iostream>
#include "shape.hpp"
#include "createShape.hpp"
#include "outRes.hpp"

int main()
{
  constexpr size_t size = 10000;
  shramko::Shape* shape[size] = {};
  size_t count = 0;
  count = shramko::createShape(std::cin, std::cerr, std::cout, shape);

  if (count == -1)
  {
    return 1;
  }

  shramko::outRes(std::cout, shape, count);

  shramko::destroy(shape, count);
  return 0;
}
