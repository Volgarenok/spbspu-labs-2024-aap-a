#include <iostream>
#include <stdexcept>
#include "destroy.hpp"
#include "printResult.hpp"
#include "createCommand.hpp"

int main()
{
  using namespace duhanina;
  Shape* shapes[10000] = {};
  size_t shapeCount = 0;
  double scalingFactor = 0;
  point_t point = { 0, 0 };
  bool errorArg = false;
  try
  {
    inputShapes(std::cin, shapes, shapeCount, errorArg);
    if (shapeCount == 0)
    {
      throw std::logic_error("No shape");
    }
    createScale(std::cin, scalingFactor, point);
    printFiguresInfo(std::cout, shapes, shapeCount);
    processScaling(shapes, shapeCount, point, scalingFactor);
    printFiguresInfo(std::cout, shapes, shapeCount);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    destroy(shapes, shapeCount);
    return 1;
  }
  if (errorArg)
  {
    std::cerr << "Invalid arguments for input shapes\n";
  }
  destroy(shapes, shapeCount);
  return 0;
}
