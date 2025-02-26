#include "rectangle.hpp"

dirti::Rectangle::Rectangle(const point_t left_low, const point_t right_high):
  left_low_(left_low),
  right_high_(right_high)
{
  if (left_low.x >= right_high.x || left_low.y >= right_high.y)
  {
    throw std::logic_error("Wrong shape");
  }
}

double dirti::Rectangle::getArea() const
{
  return (right_high_.x - left_low_.x) * (right_high_.y - left_low_.y);
}

dirti::rectangle_t dirti::Rectangle::getFrameRect() const
{
  double width = right_high_.x - left_low_.x;
  double height = right_high_.y - left_low_.y;
  point_t pos{ width / 2 + left_low_.x, height / 2 + left_low_.y };
  rectangle_t frameRect{ width, height, pos };
  return frameRect;
}

void dirti::Rectangle::move(double x, double y)
{
  left_low_ = { left_low_.x + x, left_low_.y + y };
  right_high_ = { right_high_.x + x, right_high_.y + y };
}

void dirti::Rectangle::move(point_t point)
{
  point_t pos_ = getFrameRect().pos;
  move(point.x - pos_.x, point.y - pos_.y);
}

void dirti::Rectangle::unsafeScale(double koef)
{
  rectangle_t frameRect = getFrameRect();
  point_t pos_ = frameRect.pos;
  left_low_ = { pos_.x - koef * frameRect.width / 2, pos_.y - koef * frameRect.height / 2 };
  right_high_ = { pos_.x + koef * frameRect.width / 2, pos_.y + koef * frameRect.height / 2 };
}