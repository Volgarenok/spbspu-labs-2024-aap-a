#include "rectangle.hpp"
#include <stdexcept>

balashov::Rectangle::Rectangle(double xLeft, double yUp, double xRight, double yDown)
{
  angleUpRight.x = xRight;
  angleUpRight.y = yUp;
  angleDownLeft.x = xLeft;
  angleDownLeft.y = yDown;
  сentre.x = xLeft + (xRight - xLeft) / 2;
  сentre.y = yDown + (yUp - yDown) / 2;
}

double balashov::Rectangle::getArea() const
{
  double width = angleUpRight.x - angleDownLeft.x;
  double height = angleUpRight.y - angleDownLeft.y;
  return width * height;
}

balashov::rectangle_t balashov::Rectangle::getFrameRect() const
{
  rectangle_t point = {};
  point.width = angleUpRight.x - angleDownLeft.x;
  point.height = angleUpRight.y - angleDownLeft.y;
  point.pos.x = angleDownLeft.x + (point.width / 2.0);
  point.pos.y = angleDownLeft.y + (point.height / 2.0);
  return point;
}

void balashov::Rectangle::move(double x, double y)
{
  angleUpRight.x += x;
  angleDownLeft.x += x;
  angleDownLeft.y += y;
  angleUpRight.y += y;
}

void balashov::Rectangle::move(point_t target)
{
  сentre = getFrameRect().pos;
  double distanceBetweenPointsX = target.x - сentre.x;
  double distanceBetweenPointsY = target.y - сentre.y;
  move(distanceBetweenPointsX, distanceBetweenPointsY);
}

void balashov::Rectangle::scale(double scaleCoefficient)
{
  сentre = getFrameRect().pos;
  angleDownLeft.x = сentre.x - (сentre.x - angleDownLeft.x) * scaleCoefficient;
  angleDownLeft.y = сentre.y - (сentre.y - angleDownLeft.y) * scaleCoefficient;
  angleUpRight.x = сentre.x + (angleUpRight.x - сentre.x) * scaleCoefficient;
  angleUpRight.y = сentre.y + (angleUpRight.y - сentre.y) * scaleCoefficient;
}
