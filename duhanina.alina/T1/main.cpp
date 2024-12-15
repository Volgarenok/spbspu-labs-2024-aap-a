#include <iostream>
#include "makeShape.hpp"
#include "printResult.hpp"

int main()
{
  duhanina::Shape* shapes[10000];
  size_t shapeCount = 0;
  std::string shapeType;
  bool hasScale = false;
  while (std::cin >> shapeType)
  {
    try
    {
      if (shapeType == "RECTANGLE")
      {
        shapes[shapeCount] = duhanina::makeRectangle(std::cin);
        shapeCount++;
      }
      else if (shapeType == "CIRCLE")
      {
        shapes[shapeCount] = duhanina::makeCircle(std::cin);
        shapeCount++;
      }
      else if (shapeType == "ELLIPSE")
      {
        shapes[shapeCount] = duhanina::makeEllipse(std::cin);
        shapeCount++;
      }
      else if (shapeType == "SCALE")
      {
        if (shapeCount == 0)
        {
          std::cerr << "No shape\n";
          duhanina::destroy(shapes, shapeCount);
          return 1;
        }
        double x = 0;
        double y = 0;
        duhanina::point_t point;
        std::cin >> x >> y;
        point.x = x;
        point.y = y;
        double scalingFactor = 0;
        std::cin >> scalingFactor;
        if (scalingFactor <= 0)
        {
          std::cerr << "Incorrect scalingFactor\n";
          duhanina::destroy(shapes, shapeCount);
          return 1;
        }
        hasScale = true;
        duhanina::processScaling(shapes, shapeCount, point, scalingFactor);
        break;
      }
    }
    catch (const std::invalid_argument&)
    {
      std::cerr << "Error in figure description\n";
      duhanina::destroy(shapes, shapeCount);
      continue;
    }
    catch(const std::bad_alloc& e)
    {
      std::cerr << "Error memory\n";
      duhanina::destroy(shapes, shapeCount);
      return 1;
    }
  }
  if (!hasScale)
  {
    std::cerr << "No scale\n";
    duhanina::destroy(shapes, shapeCount);
    return 1;
  }
  duhanina::destroy(shapes, shapeCount);
  return 0;
}
