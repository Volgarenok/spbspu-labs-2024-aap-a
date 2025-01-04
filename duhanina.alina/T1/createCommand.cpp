#include "createCommand.hpp"
#include "shape.hpp"
#include "makeShape.hpp"
#include "printResult.hpp"

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

void duhanina::createScale(std::istream& in, Shape** shapes, size_t shapeCount)
{
  if (shapeCount == 0)
  {
    throw std::logic_error("No shape");
  }
  double x = 0;
  double y = 0;
  double scalingFactor = 0;
  if (!(in >> x >> y >> scalingFactor))
  {
    throw std::invalid_argument("Incorrect input");
  }
  point_t point = { x, y };
  processScaling(shapes, shapeCount, point, scalingFactor);
}
