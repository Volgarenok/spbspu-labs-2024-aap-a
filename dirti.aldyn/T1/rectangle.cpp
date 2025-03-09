#include "rectangle.hpp"

dirti::Rectangle::Rectangle(const point_t left_low, const point_t right_high):
  parallelogram(left_low, { right_high.x, left_low.y }, right_high)
{
  if (left_low.x >= right_high.x || left_low.y >= right_high.y)
  {
    throw std::logic_error("Wrong shape");
  }
}

double dirti::Rectangle::getArea() const
{
  return parallelogram.getArea();
}

dirti::rectangle_t dirti::Rectangle::getFrameRect() const
{
  return parallelogram.getFrameRect();
}

void dirti::Rectangle::move(double x, double y)
{
  parallelogram.move(x, y);
}

void dirti::Rectangle::move(point_t point)
{
  parallelogram.move(point);
}

void dirti::Rectangle::scaleUnsafe(double koef)
{
  parallelogram.scaleUnsafe(koef);
}
