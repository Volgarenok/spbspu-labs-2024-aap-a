#include "square.hpp"

#include <exception>

guseynov::Square::Square(point_t leftLowP, double length)
{
  if (length <= 0)
  {
    throw std::logic_error("Invalid argumets for Square");
  }
  leftLowP_.x = leftLowP.x;
  leftLowP_.y = leftLowP.y;
  length_ = length;
}

double guseynov::Square::getArea() const
{
  return length_ * length_;
}

guseynov::rectangle_t guseynov::Square::getFrameRect() const
{
  return {length_, length_, {leftLowP_.x + (length_ / 2), leftLowP_.y + (length_ / 2)}}
}

void guseynov::Square::move(point_t pos)
{
  leftLowP_.x = pos.x - (length_ / 2);
  leftLowP_.y = pos.y - (length_ / 2);
}

void guseynov::Square::move(double x, double y)
{
  leftLowP_.x = leftLowP_.x + x;
  leftLowP_.y = leftLowP_.y + y;
}

void guseynov::Square::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Invalid argument for k");
  }
  point_t center = getFrameRect.pos;
  leftLowP_.x = center.x - (length_ / 2) * k;
  leftLowP_.y = center.y - (length_ / 2) * k;
}
