#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

double maslov::Rectangle::getArea() const
{
  return (upperRightCorner_.x - lowerLeftCorner_.x) * (upperRightCorner_.y - lowerLeftCorner_.y);
}
maslov::rectangle_t maslov::Rectangle::getFrameRect() const
{
  double centreForX = lowerLeftCorner_.x + (upperRightCorner_.x - lowerLeftCorner_.x) / 2;
  double centreForY = lowerLeftCorner_.y + (upperRightCorner_.y - lowerLeftCorner_.y) / 2;
  return { upperRightCorner_.x - lowerLeftCorner_.x, upperRightCorner_.y - lowerLeftCorner_.y, { centreForX, centreForY } };
}
void maslov::Rectangle::move(point_t a)
{
  point_t centre = this->getFrameRect().pos;
  double moveX = a.x - centre.x;
  double moveY = a.y - centre.y;
  lowerLeftCorner_.x += moveX;
  lowerLeftCorner_.y += moveY;
  upperRightCorner_.x += moveX;
  upperRightCorner_.y += moveY;
}
void maslov::Rectangle::move(double dx, double dy)
{
  lowerLeftCorner_.x += dx;
  lowerLeftCorner_.y += dy;
  upperRightCorner_.x += dx;
  upperRightCorner_.y += dy;
}