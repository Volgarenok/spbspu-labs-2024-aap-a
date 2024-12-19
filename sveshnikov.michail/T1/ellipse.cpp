#include "ellipse.hpp"
#include <cmath>

sveshnikov::Ellipse::Ellipse(point_t center, double vert_radius, double horiz_radius): 
  center_(center),
  vert_radius_(vert_radius),
  horiz_radius_(horiz_radius)
{}

double sveshnikov::Ellipse::getArea() const
{
  return M_PI * vert_radius_ * horiz_radius_;
}

sveshnikov::rectangle_t sveshnikov::Ellipse::getFrameRect() const
{
  rectangle_t frame = {0, 0, {0, 0}};
  frame.height = 2 * vert_radius_;
  frame.width = 2 * horiz_radius_;
  frame.pos.x = center_.x;
  frame.pos.y = center_.y;
  return frame;
}

void sveshnikov::Ellipse::move(point_t p)
{
  center_.x = p.x;
  center_.y = p.y;
}

void sveshnikov::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sveshnikov::Ellipse::scale(double k)
{
  vert_radius_ *= k;
  horiz_radius_ *= k;
}
