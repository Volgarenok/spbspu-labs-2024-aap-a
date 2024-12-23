#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include <limits>

balashov::Regular::Regular(point_t pnt1, point_t pnt2, point_t pnt3)
{
  point1 = pnt1;
  point2 = pnt2;
  point3 = pnt3;
}

double balashov::Regular::getArea() const
{
  double sqrLength1 = std::pow(point1.x - point2.x, 2) + std::pow(point1.y - point2.y, 2);
  double sqrLength2 = std::pow(point2.x - point3.x, 2) + std::pow(point2.y - point3.y, 2);
  double sqrLength3 = std::pow(point1.x - point3.x, 2) + std::pow(point1.y - point3.y, 2);
  double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
  double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
  double nVertices = std::round(3.14 / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse)));
  double sideLength = 2 * std::sqrt(sqrLength1 + sqrLength2 + sqrLength3 - sqrHypotenuse - sqrSmallRadius);
  return (std::pow(sideLength, 2) * nVertices) / (4 * std::tan(3.14 / nVertices));
}

balashov::rectangle_t balashov::Regular::getFrameRect() const
{
  rectangle_t point;
  point.pos = point1;
  double sqrLength1 = std::pow(point1.x - point2.x, 2) + std::pow(point1.y - point2.y, 2);
  double sqrLength2 = std::pow(point2.x - point3.x, 2) + std::pow(point2.y - point3.y, 2);
  double sqrLength3 = std::pow(point1.x - point3.x, 2) + std::pow(point1.y - point3.y, 2);

  double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
  double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
  double nVertices = std::round(3.14 / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse)));
  double bigRadius = std::sqrt(std::max(sqrLength1, sqrLength3));
  double maxX = std::numeric_limits<double>::min(), minX = std::numeric_limits<double>::max();
  double maxY = std::numeric_limits<double>::min(), minY = std::numeric_limits<double>::max();
  double angle = std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse));
  if (point1.y == point3.y)
  {
    angle = 0;
  }
  for (std::size_t i = 0; i < nVertices; ++i)
  {
    double nextAngle = i * 2 * 3.14 / nVertices + angle;
    minX = std::min(minX, point1.x + bigRadius * std::cos(nextAngle));
    minY = std::min(minY, point1.y + bigRadius * std::sin(nextAngle));
    maxX = std::max(maxX, point1.x + bigRadius * std::cos(nextAngle));
    maxY = std::max(maxY, point1.y + bigRadius * std::sin(nextAngle));
  }
  point.width = maxX - minX;
  point.height = maxY - minY;
  return point;
}

void balashov::Regular::move(point_t targer)
{
  double movedX = targer.x - point1.x;
  double movedY = targer.y - point1.y;
  move(movedX, movedY);
}

void balashov::Regular::move(double x, double y)
{
  point1 = { point1.x + x, point1.y + y };
  point2 = { point2.x + x, point2.y + y };
  point3 = { point3.x + x, point3.y + y };
}

void balashov::Regular::scale(double scaleC)
{
  point2 = { point1.x + (point2.x - point1.x) * scaleC, point1.y + (point2.y - point1.y) * scaleC };
  point3 = { point1.x + (point3.x - point1.x) * scaleC, point1.y + (point3.y - point1.y) * scaleC };
}
