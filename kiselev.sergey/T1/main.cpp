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
  bool isIncorrectScale = false;
  kiselev::point_t scale;
  double ratio = 0;
  try
  {
    while (std::cin >> titleShape)
    {
      if (titleShape == "RECTANGLE")
      {
        try
        {
          shapes[countShape] = kiselev::make_rectangle(std::cin);
          countShape++;
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectScale = true;
        }
      }
      else if (titleShape == "DIAMOND")
      {
        try
        {
          shapes[countShape] = kiselev::make_diamond(std::cin);
          countShape++;
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectScale = true;
        }
      }
      else if (titleShape == "COMPLEXQUAD")
      {
        try
        {
          shapes[countShape] = kiselev::make_complexquad(std::cin);
          countShape++;
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectScale = true;
        }
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
    if (isIncorrectScale)
    {
      std::cerr << "There was an error in the description of the scale\n";
    }
    if (countShape == 0)
    {
      std::cerr << "The scales were not passed\n";
      return 1;
    }
    std::cout << std::fixed << std::setprecision(1) << getSumArea(shapes, countShape);
    printCoordinatesRect(shapes, countShape);
    scaleForShapes(shapes, countShape, scale, ratio);
    std::cout << getSumArea(shapes, countShape);
    printCoordinatesRect(shapes, countShape);
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
