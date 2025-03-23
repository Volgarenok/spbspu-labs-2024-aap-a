#include <cstddef>
#include <iomanip>
#include <iostream>
#include "getShapeInfo.hpp"
#include "shape.hpp"

int main()
{
  constexpr size_t shapesSize = 10000;
  bocharov::Shape * shapes[shapesSize] = {};
  int shapeCount = 0;
  try
  {
    std::cout << std::fixed << std::setprecision(1);
    shapeCount = bocharov::getShapeInfo(std::cin, std::cerr, std::cout, shapes);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  if (shapeCount == 0)
  {
    return 1;
  }
  bocharov::clear(shapes, shapeCount);
  return 0;
}
