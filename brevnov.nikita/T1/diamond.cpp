#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>
namespace brevnov
{
  bool isCorrectDiamond(double x1, double y1, double x2, double y2, double x3, double y3)
  {
    if ((x1 == x2 &&  y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
    {
      return false;
    }
    else if ((x1 != x2 && x1 != x3 && x2 != x3) || (y1 != y2 && y1 != y3 && y2 != y3))
    {
      return false;
    }
    return true;
  }
}

brevnov::Diamond::Diamond(point_t a, point_t b, point_t c):
  center_({0.0, 0.0}),
  horizontal_({0.0, 0.0}),
  vertical_({0.0, 0.0})
{
  double x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y, x3 = c.x, y3 = c.y;
  if (!isCorrectDiamond(x1, y1, x2, y2, x3, y3))
  {
    throw std::invalid_argument("Not correct arguments");
  }
  if (x1 == x2 && y1 == y3)
  {
    center_ = {x1, y1};
    horizontal_ = {x3, y3};
    vertical_ = {x2, y2};
  }
  else if (x1 == x3 && y1 == y2)
  {
    center_ = {x1, y1};
    horizontal_ = {x2, y2};
    vertical_ = {x3, y3};
  }
  else if (x2 == x1 && y2 == y3)
  {
    center_ = {x2, y2};
    horizontal_ = {x3, y3};
    vertical_ = {x1, y1};
  }
  else if (x2 == x3 && y2 == y1)
  {
    center_ = {x2, y2};
    horizontal_ = {x1, y1};
    vertical_ = {x3, y3};
  }
  else if (x3 == x1 && y3 == y2)
  {
    center_ = {x3, y3};
    horizontal_ = {x2, y2};
    vertical_ = {x1, y1};
  }
  else
  {
    center_ = {x3, y3};
    horizontal_ = {x1, y1};
    vertical_ = {x2, y2};
  }
}

double brevnov::Diamond::getArea() const noexcept
{
  return (std::fabs((horizontal_.x - center_.x) * (vertical_.y - center_.y) * 2));
}

brevnov::rectangle_t brevnov::Diamond::getFrameRect() const noexcept
{
  point_t pos = center_;
  double width = std::fabs(horizontal_.x - center_.x) * 2;
  double height = std::fabs(vertical_.y - center_.y) * 2;
  rectangle_t result = {width, height, pos};
  return result;
}

void brevnov::Diamond::move(point_t new_centre) noexcept
{
  double xdif = horizontal_.x - center_.x;
  double ydif = vertical_.y - center_.y;
  center_ = new_centre;
  horizontal_ = new_centre;
  vertical_ = new_centre;
  horizontal_.x += xdif;
  vertical_.y += ydif;
}

void brevnov::Diamond::move(double dx, double dy) noexcept
{
  move_point(dx, dy, center_);
  move_point(dx, dy, horizontal_);
  move_point(dx, dy, vertical_);
}

void brevnov::Diamond::scale(double n) noexcept
{
  horizontal_.x = center_.x + (center_.x - horizontal_.x) * n;
  vertical_.y = center_.y + (center_.y - vertical_.y) * n;
}

brevnov::Shape * brevnov::Diamond::clone() const override
{
  return new Diamond(*this);
}
