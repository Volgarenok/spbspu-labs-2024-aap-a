#include <cstddef>
#include <iostream>
#include "getShapeInfo.hpp"
#include "shape.hpp"

int main()
{
  constexpr size_t shapesSize = 10000;
  bocharov::Shape * myShapes[shapesSize] = {};
  int shapeCount = 0;
  shapeCount = bocharov::getShapeInfo(std::cin, std::cerr, std::cout, myShapes);
  if (shapeCount == -1)
  {
    return 1;
  }
  bocharov::clear(myShapes, shapeCount);
  return 0;
}
