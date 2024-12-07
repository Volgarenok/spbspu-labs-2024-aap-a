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
  bool isIncorrectScale = false;
  try
  {
    while (std::cin >> titleShape)
    {
      if (titleShape == "RECTANGLE")
      {
        try
        {
          shapes[countShape++] = kiselev::make_rectangle(std::cin);
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectScale = true;
        }
        titleShape = "";
      }
      else if (std::cin.eof())
      {
        std::cerr << "The input ended with eof\n";
        kiselev::destroyShapePtr(shapes, countShape);
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
      titleShape = "";
    }
    if (isIncorrectScale)
    {
      std::cerr << "There was an error in the description of the scale\n";
    }
    if (countShape == 0)
    {
      std::cerr << "The scales were not passed\n";
      return 1;
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
    return 1;
  }
  kiselev::destroyShapePtr(shapes, countShape);
  return 0;
}
