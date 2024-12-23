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
  double x = 0;
  double y = 0;
  in >> x >> y;
  double radius = 0;
  in >> radius;
  if (radius <= 0)
  {
      throw std::invalid_argument("Error in parameters");
  }
  Circle* circ = new Circle({ x, y }, radius);
  return circ;
}

balashov::Ring* balashov::makeRing(std::istream& in)
{
  double centerX = 0;
  double centerY = 0;
  double outerRadius = 0;
  double innerRadius = 0;
  in >> centerX >> centerY >> outerRadius >> innerRadius;
  Ring* ring = new Ring({ centerX, centerY }, outerRadius, innerRadius);
  return ring;
}

void balashov::deleteShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}
