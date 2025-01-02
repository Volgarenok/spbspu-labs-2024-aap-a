#include "base-types.hpp"

#include <cmath>

double rychkov::getDistanceSqr(point_t from, point_t to)
{
  double deltaX = to.x - from.x;
  double deltaY = to.y - from.y;
  return deltaX * deltaX + deltaY * deltaY;
}
double rychkov::getSquare(point_t p1, point_t p2, point_t p3)
{
  double side1 = std::sqrt(getDistanceSqr(p1, p2));
  double side2 = std::sqrt(getDistanceSqr(p2, p3));
  double side3 = std::sqrt(getDistanceSqr(p3, p1));
  double semiperimeter = (side1 + side2 + side3) / 2;
  return std::sqrt(semiperimeter * (semiperimeter - side1)
        * (semiperimeter - side2) * (semiperimeter - side3));
}
rychkov::rectangle_t rychkov::makeFrame(point_t bottomLeft, point_t topRight)
{
  point_t center = {(bottomLeft.x + topRight.x) / 2, (bottomLeft.y + topRight.y) / 2};
  return {topRight.y - bottomLeft.y, topRight.x - bottomLeft.x, center};
}
