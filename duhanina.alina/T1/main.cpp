#include <iostream>
#include "destroy.hpp"
#include "printResult.hpp"
#include "createCommand.hpp"

using namespace duhanina;

int main()
{
  Shape* shapes[10000] = {};
  size_t shapeCount = 0;
  std::string shapeType;
  bool hasScale = false;
  while (std::cin >> shapeType)
  {
    try
    {
      createShape(shapeType, shapes, shapeCount);
      if (shapeType == "SCALE")
      {
        if (shapeCount == 0)
        {
          std::cerr << "No shape\n";
          destroy(shapes, shapeCount);
          return 1;
        }
        hasScale = true;
        createScale(std::cin, std::cout, shapes, shapeCount);
        break;
      }
    }
    catch (const std::invalid_argument&)
    {
      std::cerr << "Incorrect parameters\n";
    }
    catch (const std::logic_error&)
    {
      std::cerr << "Incorrect scale coef\n";
      destroy(shapes, shapeCount);
      return 1;
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Error memory\n";
      destroy(shapes, shapeCount);
      return 1;
    }
  }
  if (std::cin.eof())
  {
    if (!hasScale)
    {
      std::cerr << "No scale\n";
      destroy(shapes, shapeCount);
      return 1;
    }
  }
  destroy(shapes, shapeCount);
  return 0;
}
