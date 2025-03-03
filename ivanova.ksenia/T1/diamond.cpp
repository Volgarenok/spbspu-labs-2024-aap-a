#include "diamond.hpp"
#include <cmath>

ivanova::Diamond::Diamond(point_t topPoint, point_t bottomPoint, point_t center):
  topPoint_(topPoint), bottomPoint_(bottomPoint), center_(center)
{
}

double ivanova::Diamond::getArea() const
{
  return std::fabs((topPoint_.y - center_.y) * (bottomPoint_.x - center_.x) * 2);
}

ivanova::rectangle_t ivanova::Diamond::getFrameRect() const
{
  double width = std::fabs(center_.x - bottomPoint_.x) * 2;
  double height = std::fabs(center_.y - topPoint_.y) * 2;
  return { width, height, center_ };
}

void ivanova::Diamond::move(point_t point)
{
  double moveX = point.x - center_.x;
  double moveY = point.y - center_.y;
  center_ = point;
  topPoint_ = {topPoint_.x + moveX, topPoint_.y + moveY};
  bottomPoint_ = {bottomPoint_.x + moveX, bottomPoint_.y + moveY};
}

void ivanova::Diamond::move(double x, double y)
{
  center_ = {center_.x + x, center_.y + y};
  topPoint_ = {topPoint_.x + x, topPoint_.y + y};
  bottomPoint_ = {bottomPoint_.x + x, bottomPoint_.y + y};
}

void ivanova::Diamond::scale(double ratio)
{
  topPoint_.y = center_.y + (topPoint_.y - center_.y) * ratio;
  bottomPoint_.x = center_.x + (bottomPoint_.x - center_.x) * ratio;
}
