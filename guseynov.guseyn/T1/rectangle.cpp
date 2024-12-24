#include "rectangle.hpp"

guseynov::Rectangle::Rectangle(point_t leftLowP, point_t rightHighP)
{
  leftLowP_.x = leftLowP.x;
  leftLowP_.y = leftLowP.y;
  rightHighP_.x = rightHighP.x;
  rightHighP_.y = rightHighP.y;
}

double guseynov::Rectangle::getArea() const
{
  return (rightHighP_.x - leftLowP_.x) * (rightHighP_.y - leftLowP_.y);
}

guseynov::rectangle_t guseynov::Rectangle::getFrameRect() const
{
  double width = rightHighP_.x - leftLowP_.x;
  double height = rightHighP_.y - leftLowP_.y;
  return {width, height, {leftLowP_.x + (width / 2), leftLowP_.y + (height / 2)}};
}

void guseynov::Rectangle::move(point_t pos)
{
  point_t center = getFrameRect().pos;
  double moveX = pos.x - center.x;
  double moveY = pos.y - center.y;
  this->leftLowP_.x += moveX;
  this->leftLowP_.y += moveY;
  this->rightHighP_.x += moveX;
  this->rightHighP_.y += moveY;
}

void guseynov::Rectangle::move(double x, double y)
{
  this->leftLowP_.x += x;
  this->leftLowP_.y += y;
  this->rightHighP_.x += x;
  this->rightHighP_.y += y;
}

void guseynov::Rectangle::scale(double k)
{
  point_t center = getFrameRect().pos;
  this->leftLowP_.x = center.x - (center.x - leftLowP_.x) * k;
  this->leftLowP_.y = center.y - (center.y - leftLowP_.y) * k;
  this->rightHighP_.x = center.x + (center.x - rightHighP_.x) * k;
  this->rightHighP_.y = center.y + (center.y - rightHighP_.y) * k;
}
