#include "square.hpp"

#include <stdexcept>

guseynov::Square::Square(point_t leftLowP, double length):
  leftLowP_(leftLowP),
  length_(length)
{
  if (length <= 0)
  {
    throw std::invalid_argument("Error in SQUARE parameters");
  }
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
  assigment({pos.x - (length_ / 2), pos.y - (length_ / 2)});
}

void guseynov::Square::move(double x, double y)
{
  assigment({leftLowP_.x + x, leftLowP_.y + y});
}

void guseynov::Square::scale(double k)
{
  assigment({leftLowP_.x - (length_ * k - length_) / 2, leftLowP_.y - (length_ * k - length_) / 2});
  length_ *= k;
}

void guseynov::Square::assigment(point_t leftLowP)
{
  leftLowP_ = leftLowP;
}
