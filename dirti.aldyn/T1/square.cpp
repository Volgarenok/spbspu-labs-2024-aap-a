#include "square.hpp"

dirti::Square::Square(const point_t left_low, const double length):
  left_low_(left_low),
  length_(length)
{
  if (length <= 0.0)
  {
    throw std::logic_error("Wrong shape");
  }
}

double dirti::Square::getArea() const
{
  return (length_ * length_);
}

dirti::rectangle_t dirti::Square::getFrameRect() const
{
  double width = length_;
  double height = length_;
  point_t pos{ left_low_.x + length_ / 2, left_low_.y + length_ / 2 };
  rectangle_t frameRect{ width, height, pos };
  return frameRect;
}

void dirti::Square::move(double x, double y)
{
  left_low_ = { left_low_.x + x, left_low_.y + y };
}

void dirti::Square::move(point_t point)
{
  point_t pos_ = getFrameRect().pos;
  move(point.x - pos_.x, point.y - pos_.y);
}

void dirti::Square::scaleUnsafe(double koef)
{
  rectangle_t frameRect = getFrameRect();
  point_t pos_ = frameRect.pos;
  length_ *= koef;
  left_low_ = { pos_.x - length_ / 2, pos_.y - length_ / 2 };
}
