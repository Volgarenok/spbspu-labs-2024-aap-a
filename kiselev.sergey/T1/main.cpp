#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <inputString.h>
#include "actionShapes.hpp"
#include "makeShapes.hpp"
#include "shape.hpp"
int main()
{
  kiselev::Shape* shapes[1000] = {};
  size_t countShape = 0;
  std::string titleShape;
  bool isIncorrectShape = false;
  kiselev::point_t scale;
  double ratio = 0;
  try
  {
    while (std::cin >> titleShape)
    {
      try
      {
        if (titleShape == "RECTANGLE")
        {
          shapes[countShape] = kiselev::make_rectangle(std::cin);
          countShape++;
        }
        else if (titleShape == "DIAMOND")
        {
          shapes[countShape] = kiselev::make_diamond(std::cin);
          countShape++;
        }
        else if (titleShape == "COMPLEXQUAD")
        {
          shapes[countShape] = kiselev::make_complexquad(std::cin);
          countShape++;
        }
        else if (std::cin.eof())
        {
          std::cerr << "The input ended with eof\n";
          kiselev::destroyShapePtr(shapes, countShape);
          return 1;
        }
        else if (titleShape == "SCALE")
        {
          scale = kiselev::make_scale(std::cin);
          std::cin >> ratio;
          if (ratio <= 0)
          {
            std::cerr << "Incorrect ratio\n";
            kiselev::destroyShapePtr(shapes, countShape);
            return 1;
          }
          break;
        }
      }
      catch (std::invalid_argument& e)
      {
        isIncorrectShape = true;
      }
    }
    if (isIncorrectShape)
    {
      std::cerr << "There was an error in the description of the scale\n";
    }
    if (countShape == 0)
    {
      std::cerr << "The scales were not passed\n";
      return 1;
    }
    std::cout << std::fixed << std::setprecision(1) << getSumArea(shapes, countShape);
    kiselev::printCoordinatesRect(std::cout, shapes, countShape);
    kiselev::scaleForShapes(shapes, countShape, scale, ratio);
    std::cout << getSumArea(shapes, countShape);
    kiselev::printCoordinatesRect(std::cout, shapes, countShape);
    kiselev::destroyShapePtr(shapes, countShape);
    return 0;
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
}
