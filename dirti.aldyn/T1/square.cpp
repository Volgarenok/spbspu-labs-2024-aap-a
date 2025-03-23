#include "square.hpp"

dirti::Square::Square(const point_t left_low, const double length):
  rectangle(left_low, { left_low.x + length, left_low.y + length })
{}

double dirti::Square::getArea() const
{
  return rectangle.getArea();
}

dirti::rectangle_t dirti::Square::getFrameRect() const
{
  return rectangle.getFrameRect();
}

void dirti::Square::move(double x, double y)
{
  rectangle.move(x, y);
}

void dirti::Square::move(point_t point)
{
  rectangle.move(point);
}

void dirti::Square::scaleUnsafe(double koef)
{
  rectangle.scaleUnsafe(koef);
}
