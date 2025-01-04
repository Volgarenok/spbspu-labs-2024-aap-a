#include <cstddef>
#include <iostream>
#include "getShapeInfo.hpp"
#include "shape.hpp"

int main()
{
  constexpr size_t shapesSize = 10000;
  bocharov::Shape * myShapes[shapesSize] = {};
  int shapeCount = 0;
  try
  {
    shapeCount = bocharov::getShapeInfo(std::cin, std::cerr, std::cout, myShapes);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << '\n';
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << '\n';
  }
  if (shapeCount == 0)
  {
    return 1;
  }
  bocharov::clear(myShapes, shapeCount);
  return 0;
}
