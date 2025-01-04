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
  while (std::cin >> shapeType)
  {
    try
    {
      createShape(shapeType, shapes, shapeCount);
      if (shapeType == "SCALE")
      {
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
  createScale(std::cin, shapes, shapeCount);
  printFiguresInfo(std::cout, shapes, shapeCount);
  destroy(shapes, shapeCount);
  return 0;
}
