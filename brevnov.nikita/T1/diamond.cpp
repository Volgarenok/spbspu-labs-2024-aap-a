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
  return (std::fabs((horizontal_.x_ - center_.x_) * (vertical_.y_ - center_.y_) * 2));
}

brevnov::rectangle_t brevnov::Diamond::getFrameRect() const noexcept
{
  point_t pos = center_;
  double width = std::fabs(horizontal_.x_ - center_.x_) * 2;
  double height = std::fabs(vertical_.y_ - center_.y_) * 2;
  rectangle_t result(width, height, pos);
  return result;
}

void brevnov::Diamond::move(point_t new_centre) noexcept
{
  double xdif = horizontal_.x_ - center_.x_;
  double ydif = vertical_.y_ - center_.y_;
  center_ = new_centre;
  horizontal_ = new_centre;
  vertical_ = new_centre;
  horizontal_.x_ += xdif;
  vertical_.y_ += ydif;
}

void brevnov::Diamond::move(double dx, double dy) noexcept
{
  center_.x_ += dx;
  horizontal_.x_ += dx;
  vertical_.x_ += dx;
  center_.y_ += dy;
  horizontal_.y_ += dy;
  vertical_.y_ += dy;
}

void brevnov::Diamond::scale(double n) noexcept
{
  horizontal_.x_ = center_.x_ + (center_.x_ - horizontal_.x_) * n;
  vertical_.y_ = center_.y_ + (center_.y_ - vertical_.y_) * n;
}
