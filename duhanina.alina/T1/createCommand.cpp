#include "createCommand.hpp"
#include "shape.hpp"
#include "makeShape.hpp"
#include "printResult.hpp"

void duhanina::createShape(const std::string& shapeType, Shape** shapes, size_t& shapeCount)
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
}

void duhanina::createScale(std::istream& in, std::ostream& out, Shape** shapes, size_t shapeCount)
{
  double x = 0;
  double y = 0;
  double scalingFactor = 0;
  if (!(in >> x >> y >> scalingFactor))
  {
    throw std::invalid_argument("Incorrect input");
  }
  duhanina::point_t point;
  point.x = x;
  point.y = y;
  duhanina::printFiguresInfo(out, shapes, shapeCount);
  duhanina::processScaling(shapes, shapeCount, point, scalingFactor);
  duhanina::printFiguresInfo(out, shapes, shapeCount);
}
