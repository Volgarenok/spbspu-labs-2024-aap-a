#include "createShape.hpp"

balashov::Rectangle* balashov::makeRectangle(std::istream& in)
{
  double xLeft = 0;
  double yUp = 0;
  double xRight = 0;
  double yDown = 0;

  in >> xLeft >> yDown >> xRight >> yUp;
  if (xLeft >= xRight || yDown >= yUp)
  {
    throw std::invalid_argument("There can be no such coordinates");
  }
  Rectangle* rectangle = new Rectangle(xLeft, yUp, xRight, yDown);
  return rectangle;
}

balashov::Circle* balashov::makeCircle(std::istream& in)
{
  point_t center = {};
  double radius = 0;
  double x = 0;
  double y = 0;
  in >> x >> y;
  center.x_ = x;
  center.y_ = y;
  in >> radius;
  if (radius < 0)
  {
    throw std::invalid_argument("There can be no such coordinates");
  }
  Circle* circle = new Circle(center, radius);
  return circle;
}

void balashov::deleteShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}
