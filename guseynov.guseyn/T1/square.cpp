#include "square.hpp"

guseynov::Square::Square(point_t leftLowP, double length) :
  leftLowP_(leftLowP), length_(length)
{
}

double guseynov::Square::getArea() const
{
  return length_ * length_;
}

guseynov::rectangle_t guseynov::Square::getFrameRect() const
{
  return {length_, length_, {leftLowP_.x + (length_ / 2), leftLowP_.y + (length_ / 2)}};
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
  leftLowP_.x -= (length_ * k - length_) / 2;
  leftLowP_.y -= (length_ * k - length_) / 2;
  length_ *= k;
}
