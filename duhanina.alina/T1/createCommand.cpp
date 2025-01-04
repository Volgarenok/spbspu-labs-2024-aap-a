#include "createCommand.hpp"
#include <iostream>
#include <stdexcept>
#include "shape.hpp"
#include "makeShape.hpp"
#include "printResult.hpp"
#include "destroy.hpp"

void duhanina::createShape(const std::string& shapeType, Shape** shapes, size_t& shapeCount)
{
  if (shapeType == "RECTANGLE")
  {
    shapes[shapeCount] = makeRectangle(std::cin);
    shapeCount++;
  }
  else if (shapeType == "CIRCLE")
  {
    shapes[shapeCount] = makeCircle(std::cin);
    shapeCount++;
  }
  else if (shapeType == "ELLIPSE")
  {
    shapes[shapeCount] = makeEllipse(std::cin);
    shapeCount++;
  }
}

void duhanina::createScale(std::istream& in, size_t shapeCount, double& scalingFactor, point_t& point)
{
  if (shapeCount == 0)
  {
    throw std::logic_error("No shape");
  }
  double x = point.x;
  double y = point.y;
  if (!(in >> x >> y >> scalingFactor))
  {
    throw std::invalid_argument("Incorrect input");
  }
  if (scalingFactor <= 0)
  {
    throw std::logic_error("Incorrect scalingFactor");
  }
  point = { x, y };
}

void duhanina::inputShapes(std::ostream& out, duhanina::Shape** shapes, size_t& shapeCount)
{
  std::string shapeType;
  while (std::cin >> shapeType && shapeType != "SCALE")
  {
    try
    {
      duhanina::createShape(shapeType, shapes, shapeCount);
    }
    catch (const std::invalid_argument& e)
    {
      out << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
      out << e.what() << "\n";
      destroy(shapes, shapeCount);
    }
  }
}
