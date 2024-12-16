#include "diamond.hpp"
#include <cmath>
#include "base-types.hpp"

lebedev::Diamond::Diamond(point_t centre, point_t vert, point_t horiz) :
  centre_(centre), vert_(vert), horiz_(horiz)
{}

double lebedev::Diamond::getArea() const
{
  return std::fabs((vert_.y - centre_.y) * (horiz_.x - centre_.x) * 2);
}

lebedev::rectangle_t lebedev::Diamond::getFrameRect() const
{
  double width = std::fabs(centre_.x - horiz_.x) * 2;
  double height = std::fabs(centre_.y - vert_.y) * 2;
  return { width, height, centre_ };
}

void lebedev::Diamond::move(point_t p)
{
  double dx = p.x - centre_.x;
  double dy = p.y - centre_.y;
  centre_ = p;
  vert_.x += dx;
  horiz_.x += dx;
  vert_.y += dy;
  horiz_.y += dy;
}

void lebedev::Diamond::move(double dx, double dy)
{
  centre_.x += dx;
  vert_.x += dx;
  horiz_.x += dx;
  centre_.y += dy;
  vert_.y += dy;
  horiz_.y += dy;
}

void lebedev::Diamond::scale(double k)
{
  vert_.y = centre_.y + (vert_.y - centre_.y) * k;
  horiz_.x = centre_.x + (horiz_.x - centre_.x) * k;
}
