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
  std::string shapeType;
  double scalingFactor = 0;
  point_t point = { 0, 0 };
  while (std::cin >> shapeType)
  {
    try
    {
      createShape(shapeType, shapes, shapeCount);
      if (shapeType == "SCALE")
      {
        createScale(std::cin, shapeCount, scalingFactor, point);
        break;
      }
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
  }
  if (std::cin.eof())
  {
    std::cerr << "No scale\n";
    destroy(shapes, shapeCount);
    return 1;
  }
  printFiguresInfo(std::cout, shapes, shapeCount);
  processScaling(shapes, shapeCount, point, scalingFactor);
  printFiguresInfo(std::cout, shapes, shapeCount);
  destroy(shapes, shapeCount);
  return 0;
}
