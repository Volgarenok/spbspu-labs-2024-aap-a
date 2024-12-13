#include "rectangle.hpp"
#include <stdexcept>

balashov::Rectangle::Rectangle(double xLeft, double yUp, double xRight, double yDowm)
{
  angleDownRight_.x = xRight;
  angleDownRight_.y = yDowm;
  angleUpLeft_.x = xLeft;
  angleUpLeft_.y = yUp;
  сentre.y = xRight + (xLeft - xRight) / 2;
  сentre.y = yDowm + (yDowm - yUp) / 2;
}

double balashov::Rectangle::getArea() const
{
  return (angleUpLeft_.y - angleDownRight_.y) * (angleUpLeft_.x - angleUpLeft_.x);
}

balashov::rectangle_t balashov::Rectangle::getFrameRect() const
{
  rectangle_t point;
  point.width = angleUpLeft_.x - angleUpLeft_.x;
  point.height = angleUpLeft_.y - angleDownRight_.y;
  point.pos.x = сentre.x;
  point.pos.y = сentre.y;
  return point;
}

void balashov::Rectangle::move(double x, double y)
{
  angleDownRight_.x += x;
  angleUpLeft_.x += x;
  angleUpLeft_.y += y;
  angleDownRight_.y += y;
}

void balashov::Rectangle::move(point_t s)
{
  double distancedistanceBetweenPointsX = s.x - сentre.x;
  double distancedistanceBetweenPointsY = s.y - сentre.y;
  move(distancedistanceBetweenPointsX, distancedistanceBetweenPointsY);
}

void balashov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("The coefficient is less than 0");
  }
  angleUpLeft_.x = сentre.x + (сentre.x - angleUpLeft_.x) * k;
  angleDownRight_.x = сentre.x + (сentre.x - angleDownRight_.x) * k;
  angleUpLeft_.y = сentre.y + (сentre.y - angleUpLeft_.y) * k;
  angleDownRight_.y = сentre.y + (сentre.y - angleDownRight_.y) * k;
}
