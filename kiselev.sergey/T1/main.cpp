#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <inputString.h>
#include "base-types.hpp"
#include "makeShapes.hpp"
#include "shape.hpp"
int main()
{
  kiselev::Shape* shapes[1000] = {};
  size_t countShape = 0;
  std::string titleShape;
  try
  {
    while (std::cin >> titleShape)
    {
      if (titleShape == "RECTANGLE")
      {
        shapes[countShape++] = kiselev::make_rectangle(std::cin);
        titleShape = "";
      }
      else if (std::cin.eof())
      {
        std::cerr << "The input ended with eof\n";
        return 1;
      }
      else if (titleShape == "SCALE")
      {
        kiselev::point_t scale = kiselev::make_scale(std::cin);
        double ratio = 0;
        std::cin >> ratio;
        if (ratio <= 0)
        {
          std::cerr << "Incorrect ratio\n";
          return 1;
        }
        break;
      }
      else if (titleShape.empty())
      {
        continue;
      }
      else
      {
        char* unusedCoordinates = kiselev::inputString(std::cin, '\n');
        if (!unusedCoordinates)
        {
          return 1;
        }
        free(unusedCoordinates);
        titleShape = "";
      }
    }
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    kiselev::destroyShapePtr(shapes, countShape);
    return 1;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory was not allocated\n";
    kiselev::destroyShapePtr(shapes, countShape);
  }
  kiselev::destroyShapePtr(shapes, countShape);
  return 0;
}
