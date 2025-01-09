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

balashov::rectangle_t balashov::Regular::getFrameRect() const
{
  rectangle_t point;
  return point;
}

double balashov::Regular::getArea() const
{
  return 0;
}
