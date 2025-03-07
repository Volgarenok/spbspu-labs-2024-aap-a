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

  try
  {
    count = shramko::createShape(std::cin, std::cerr, std::cout, shape);

    if (count == static_cast< size_t >(-1))
    {
      shramko::destroy(shape, count);
      return 1;
    }

    shramko::outRes(std::cout, shape, count);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    shramko::destroy(shape, count);
    return 1;
  }

  shramko::destroy(shape, count);
  return 0;
}
