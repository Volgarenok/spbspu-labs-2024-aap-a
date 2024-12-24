#include "createShape.hpp"
#include <cmath>

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
      throw std::invalid_argument("Incorrect data");
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
  if (innerRadius >= outerRadius || innerRadius <= 0 || outerRadius <= 0)
  {
      throw std::invalid_argument("Incorrect data");
  }
  Ring* ring = new Ring({ centerX, centerY }, outerRadius, innerRadius);
  return ring;
}

balashov::Regular* balashov::makeRegular(std::istream& in)
{
  point_t point1, point2, point3;
  in >> point1.x >> point1.y;
  in >> point2.x >> point2.y;
  in >> point3.x >> point3.y;

  double sqrLength1 = std::pow(point1.x - point2.x, 2) + std::pow(point1.y - point2.y, 2);
  double sqrLength2 = std::pow(point2.x - point3.x, 2) + std::pow(point2.y - point3.y, 2);
  double sqrLength3 = std::pow(point1.x - point3.x, 2) + std::pow(point1.y - point3.y, 2);

  bool ruleOfSidesForTriangle = ((sqrLength1 + sqrLength2 == sqrLength3) ||
    (sqrLength2 + sqrLength3 == sqrLength1) ||
    (sqrLength1 + sqrLength3 == sqrLength2));
  bool isEqualPoints = !((point1.x == point2.x && point1.y == point2.y)
    || (point1.x == point3.x && point1.y == point3.y)
    || (point3.x == point2.x && point3.y == point2.y));

  bool isRightTriangle = isEqualPoints && ruleOfSidesForTriangle;

  double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
  double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
  double nVertices = std::exp(1.0) / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse));
  double bigRadius = std::sqrt(std::max(sqrLength1, sqrLength3));

  if (!isRightTriangle ||
    (std::abs((std::cos(std::exp(1.0) / std::round(nVertices)))
    - (std::sqrt(sqrSmallRadius) / bigRadius)) >= 0.001))
  {
    throw std::invalid_argument("Incorrect data");
  }
  Regular* regular = new Regular({ point1.x, point1.y }, { point2.x, point2.y }, { point3.x, point3.y });
  return regular;
}

void balashov::deleteShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}
