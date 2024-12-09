#include "diamond.hpp"
#include <cmath>
#include "base-types.hpp"
#include "cmath"
kiselev::Diamond::Diamond(kiselev::point_t center, kiselev::point_t pVertical, point_t pHorizontal) :
  center_(center), pVertical_(pVertical), pHorizontal_(pHorizontal)
{
}
double kiselev::Diamond::getArea() const
{
  return std::fabs((center_.x - pHorizontal_.x) * (center_.y - pVertical_.y) * 2);
}
kiselev::rectangle_t kiselev::Diamond::getFrameRect() const
{
  return { std::fabs((center_.x - pHorizontal_.x)) * 2, std::fabs((center_.y - pVertical_.y) * 2), center_ };
}
void kiselev::Diamond::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  pVertical_.x += dx;
  pVertical_.y += dy;
  pHorizontal_.x += dx;
  pHorizontal_.y += dy;
}
void kiselev::Diamond::move(kiselev::point_t a)
{
  double moveForX = a.x - center_.x;
  double moveForY = a.y - center_.y;
  center_ = a;
  pVertical_.x += moveForX;
  pVertical_.y += moveForY;
  pHorizontal_.x += moveForX;
  pHorizontal_.y += moveForY;
}
void kiselev::Diamond::scale(double k)
{
  pVertical_.y = center_.y + (pVertical_.y - center_.y) * k;
  pHorizontal_.x = center_.x + (pHorizontal_.x - center_.x) * k;
}

