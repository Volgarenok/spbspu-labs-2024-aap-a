#include <iostream>
#include "createShape.hpp"
#include "shapeChanger.hpp"

int main()
{
  balashov::Shape* shapes[1000] = {};
  size_t shapeCount = 0;
  std::string shapeType = "";
  bool shapeScaled = false;
  bool incorrectrRecordShapes = false;
  balashov::point_t pointCenter = {};
  double scaleCoefficient = 0;
  if (std::cin.eof())
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  while (std::cin >> shapeType)
  {
    if (shapeType == "RECTANGLE")
    {
        try
        {
            shapes[shapeCount] = balashov::makeRectangle(std::cin);
            shapeCount++;
        }
        catch (const std::invalid_argument&)
        {
            incorrectrRecordShapes = true;
        }
    }
    if (shapeType == "CIRCLE")
    {
        try
        {
            shapes[shapeCount] = balashov::makeCircle(std::cin);
            shapeCount++;
        }
        catch (const std::invalid_argument&)
        {
            incorrectrRecordShapes = true;
        }
    }
    if (shapeType == "RING")
    {
      try
      {
        shapes[shapeCount] = balashov::makeRing(std::cin);
        shapeCount++;
      }
      catch (const std::invalid_argument&)
      {
        incorrectrRecordShapes = true;
      }
    }
    if (shapeType == "REGULAR")
    {
        try
        {
        }
        catch (const std::invalid_argument&)
        {
            incorrectrRecordShapes = true;
        }
    }
    if (shapeType == "SCALE")
    {
      if (shapeCount == 0)
      {
        std::cerr << "No shape\n";
        balashov::deleteShapes(shapes, shapeCount);
        return 1;
      }
      double x = 0;
      double y = 0;
      std::cin >> x >> y;
      pointCenter.x = x;
      pointCenter.y = y;
      std::cin >> scaleCoefficient;
      if (scaleCoefficient <= 0)
      {
        std::cerr << "Incorrect scaling\n";
        balashov::deleteShapes(shapes, shapeCount);
        return 1;
      }
      shapeScaled = true;
      break;
    }
  }
  if (!shapeScaled)
  {
    std::cerr << "Shape not scaled\n";
    balashov::deleteShapes(shapes, shapeCount);
    return 1;
  }
  balashov::printShapeInfo(shapes, shapeCount);
  balashov::scaling(shapes, shapeCount, pointCenter, scaleCoefficient);
  balashov::printShapeInfo(shapes, shapeCount);
  balashov::deleteShapes(shapes, shapeCount);
  if (incorrectrRecordShapes)
  {
    std::cerr << "The presence of an error in writing the supported shapes\n";
  }
  return 0;
}
