#include <iostream>
#include <iomanip>
#include <string>
#include <getString.h>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include "stringManip.h"
#include "shapeManip.h"

int main()
{
  bool wasDescriptionError = 0;
  constexpr const size_t maxShapes = 10000;
  aleksandrov::Shape* shapes[maxShapes] = {};
  std::string inputStr;
  char* str = nullptr;
  size_t count = 0;
  try
  {
    double sumBefore = 0;
    std::string scaleDescription;
    while ((str = aleksandrov::getString(std::cin)) && !std::cin.eof())
    {
      inputStr = str;
      delete[] str;
      str = nullptr;
      aleksandrov::Shape* shape = aleksandrov::makeShape(inputStr, wasDescriptionError);
      if (!shape)
      {
        if (aleksandrov::getWord(inputStr, 1) == "SCALE")
        {
          scaleDescription = inputStr;
          break;
        }
        continue;
      }
      shapes[count++] = shape;
      sumBefore += shape->getArea();
    }

    double x = 0.0, y = 0.0, k = 0.0;
    std::string params = aleksandrov::getScaleParams(scaleDescription, x, y, k);
    if (params == "")
    {
      std::cerr << "ERROR: There was no correct SCALE command description!\n";
      aleksandrov::deleteShapes(shapes, count);
      delete[] str;
      return 1;
    }
    if (count == 0)
    {
      std::cerr << "ERROR: There were no supporting shapes!\n";
      delete[] str;
      return 1;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << sumBefore << " ";
    aleksandrov::printFrameRectCoords(shapes, count);

    double sumAfter = 0;
    aleksandrov::doScale(shapes, count, x, y, k, sumAfter);
    std::cout << sumAfter << " ";
    aleksandrov::printFrameRectCoords(shapes, count);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "ERROR: Out of memory!\n";
    aleksandrov::deleteShapes(shapes, count);
    return 1;
  }

  aleksandrov::deleteShapes(shapes, count);

  if (wasDescriptionError)
  {
    std::cerr << "WARNING: Some supporting shapes had a description problems!\n";
  }
  delete[] str;
}

