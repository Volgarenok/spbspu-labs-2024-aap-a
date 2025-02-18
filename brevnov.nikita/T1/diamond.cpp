#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

bool isCorrectDiamond(brevnov::point_t a, brevnov::point_t b, brevnov::point_t c)
{
  if ((a.x == b.x &&  a.y == b.y) || (a.x == c.x && a.y == c.y) || (b.x == c.x && b.y == c.y))
  {
    return false;
  }
  else if ((a.x != b.x && a.x != c.x && b.x != c.x) || (a.y != b.y && a.y != c.y && b.y != c.y))
  {
    return false;
  }
  return true;
}


brevnov::point_t getCenter(brevnov::point_t a, brevnov::point_t b, brevnov::point_t c)
{
  if ((a.x == b.x && a.y == c.y) || (a.y == b.y && a.x == c.x))
  {
    return a;
  }
  else if ((b.x == a.x && b.y == c.y) || (b.y == a.y && b.x == c.x))
  {
    return b;
  }
  else
  {
    return c;
  }
}

brevnov::point_t getHorizontal(brevnov::point_t center, brevnov::point_t a, brevnov::point_t b, brevnov::point_t c)
{
  if (center.x != a.x && center.y == a.y)
  {
    return a;
  }
  else if (center.x != b.x && center.y == b.y)
  {
    return b;
  }
  else
  {
    return c;
  }
}

brevnov::point_t getVertical(brevnov::point_t center, brevnov::point_t horizontal,
  brevnov::point_t a, brevnov::point_t b, brevnov::point_t c)
{
  if ((a.x != center.x || a.y != center.y) && (a.x != horizontal.x || a.y != horizontal.y))
  {
    return a;
  }
  else if ((b.x != center.x || b.y != center.y) && (b.x != horizontal.x || b.y != horizontal.y))
  {
    return b;
  }
  else
  {
    return c;
  }
}

brevnov::Diamond::Diamond(brevnov::point_t a, brevnov::point_t b, brevnov::point_t c):
  center_(getCenter(a, b, c)),
  horizontal_(getHorizontal(center_, a, b, c)),
  vertical_(getVertical(center_, horizontal_, a, b, c))
{
  if (!isCorrectDiamond(a, b, c))
  {
    throw std::invalid_argument("Not correct arguments");
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

brevnov::Shape * brevnov::Diamond::clone() const
{
  return new Diamond(*this);
}
