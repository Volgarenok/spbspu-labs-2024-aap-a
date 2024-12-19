#include "diamond.hpp"
#include "base-types.hpp"
#include "cmath"

lanovenko::Diamond::Diamond(point_t center, point_t py, point_t px) : center_(center), py_(py), px_(px) {}

double lanovenko::Diamond::getArea() const
{
  return std::fabs((center_.x - px_.x) * (center_.y - py_.y) * 2);
}

lanovenko::rectangle_t lanovenko::Diamond::getFrameRect() const
{
  return { std::fabs((center_.x - px_.x)) * 2, std::fabs((center_.y - py_.y) * 2), center_ };
}

void lanovenko::Diamond::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  py_.x += dx;
  py_.y += dy;
  px_.x += dx;
  px_.y += dy;
}

void lanovenko::Diamond::move(point_t a)
{
  double bias_x = a.x - center_.x;
  double bias_y = a.y - center_.y;
  center_ = a;
  py_.x += bias_x;
  py_.y += bias_y;
  px_.x += bias_x;
  px_.y += bias_y;
}

void lanovenko::Diamond::unsScale(double k)
{
  py_.y = center_.y + (py_.y - center_.y) * k;
  px_.x = center_.x + (px_.x - center_.x) * k;
}
