#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

brevnov::Diamond::Diamond(point_t center, point_t horizontal, point_t vertical):
  center_(center),
  horizontal_(horizontal),
  vertical_(vertical)
{
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
  rectangle_t result(width, height, pos);
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
  center_.x += dx;
  horizontal_.x += dx;
  vertical_.x += dx;
  center_.y += dy;
  horizontal_.y += dy;
  vertical_.y += dy;
}

void brevnov::Diamond::scale(double n) noexcept
{
  horizontal_.x = center_.x + (center_.x - horizontal_.x) * n;
  vertical_.y = center_.y + (center_.y - vertical_.y) * n;
}
