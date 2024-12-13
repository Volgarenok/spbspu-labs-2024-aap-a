#include "rectangle.hpp"
#include <stdexcept>

brevnov::Rectangle::Rectangle(point_t left, point_t right) : left(left), right(right) {}

double brevnov::Rectangle::getArea()
{
  return (right.x - left.x) * (right.y - left.y);
}

brevnov::Rectangle::~Rectangle(){}

brevnov::rectangle_t brevnov::Rectangle::getFrameRect()
{
  rectangle_t result;
  result.width = right.x - left.x;
  result.height = right.y - left.y;
  result.pos = {result.width / 2.0, result.height / 2.0};
  return result;
}

void brevnov::Rectangle::move(point_t new_centre)
{
  point_t old_centre = getFrameRect().pos;
  double dx = new_centre.x - old_centre.x;
  double dy = new_centre.y - old_centre.y;
  move(dx, dy);
}

void brevnov::Rectangle::move(double dx, double dy)
{
  left.x += dx;
  left.y += dy;
  right.x += dx;
  right.y += dy;
}

void brevnov::Rectangle::scale(double n)
{
  if (n <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  point_t centre = getFrameRect().pos;
  left.x = centre.x + (left.x - centre.x) * n;
  left.y = centre.y + (left.y - centre.y) * n;
  right.x = centre.x + (right.x - centre.x) * n;
  right.y = centre.y + (right.y - centre.y) * n;
}
