#include "diamond.hpp"
#include <cmath>
#include <stdexcept>


ivanova::Diamond::Diamond(point_t topPoint, point_t bottomPoint, point_t center)
    : topPoint_(topPoint), bottomPoint_(bottomPoint), center_(center)
{
  if ((topPoint.x == bottomPoint.x && topPoint.y == bottomPoint.y) ||
    (topPoint.x == center.x && topPoint.y == center.y) ||
    (bottomPoint.x == center.x && bottomPoint.y == center.y))
  {
    throw std::invalid_argument("Some points are the same");
  }

  double dx1 = topPoint_.x - bottomPoint_.x;
  double dy1 = topPoint_.y - bottomPoint_.y;
  double dx2 = center_.x - (topPoint_.x + bottomPoint_.x) / 2;
  double dy2 = center_.y - (topPoint_.y + bottomPoint_.y) / 2;

  if (std::abs(dx1 * dx2 + dy1 * dy2) > 1e-6)
  {
    throw std::invalid_argument("Invalid diamond shape: diagonals are not perpendicular");
  }
}

double ivanova::Diamond::getArea() const
{
  double d1 = std::fabs(topPoint_.y - bottomPoint_.y);
  double d2 = std::fabs(bottomPoint_.x - center_.x) * 2;
  return (d1 * d2) / 2;
}

ivanova::rectangle_t ivanova::Diamond::getFrameRect() const
{
  double width = std::fabs(bottomPoint_.x - center_.x) * 2;
  double height = std::fabs(topPoint_.y - center_.y) * 2;
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
  if (ratio <= 0)
  {
    throw std::invalid_argument("Scale ratio must be positive.");
  }
  topPoint_.x = center_.x + (topPoint_.x - center_.x) * ratio;
  topPoint_.y = center_.y + (topPoint_.y - center_.y) * ratio;
  bottomPoint_.x = center_.x + (bottomPoint_.x - center_.x) * ratio;
  bottomPoint_.y = center_.y + (bottomPoint_.y - center_.y) * ratio;
}
