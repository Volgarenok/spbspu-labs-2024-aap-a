#include "diamond.hpp"

#include <stdexcept>

guseynov::Diamond::Diamond(point_t highP, point_t rightP, point_t center):
  highP_(highP),
  rightP_(rightP),
  center_(center)
{
}

double guseynov::Diamond::getArea() const
{
  return (rightP_.x - center_.x) * 4 * (highP_.y - center_.y);
}

guseynov::rectangle_t guseynov::Diamond::getFrameRect() const
{
  return {(rightP_.x - center_.x) * 2, (highP_.y - center_.y) * 2, center_};
}

void guseynov::Diamond::move(point_t pos)
{
  double moveX = pos.x - center_.x;
  double moveY = pos.y - center_.y;
  assigment({highP_.x + moveX, highP_.y + moveY},
  {rightP_.x + moveX, rightP_.y + moveY},
  pos);
}

void guseynov::Diamond::move(double x, double y)
{
  assigment({highP_.x + x, highP_.y + y},
  {rightP_.x + x, rightP_.y + y},
  {center_.x + x, center_.y + y});
}

void guseynov::Diamond::scaleWithoutCheck(double k)
{
  highP_.y = center_.y + (highP_.y - center_.y) * k;
  rightP_.x = center_.x + (rightP_.x - center_.x) * k;
}

void guseynov::Diamond::assigment(point_t highP, point_t rightP, point_t center)
{
  highP_ = highP;
  rightP_ = rightP;
  center_ = center;
}

guseynov::Shape * guseynov::Diamond::clone() const
{
  return new Diamond(highP_, rightP_, center_);
}
