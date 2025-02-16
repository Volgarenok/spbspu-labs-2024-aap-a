#include "circle.hpp"
#include <stdexcept>
#include "base-types.hpp"

aleksandrov::Circle::Circle(const point_t& center, double r):
  ellipse_(center, r, r)
{
  if (r <= 0)
  {
    throw std::logic_error("Incorrect radius");
  }
}

double aleksandrov::Circle::getArea() const
{
  return ellipse_.getArea();
}

aleksandrov::rectangle_t aleksandrov::Circle::getFrameRect() const
{
  return ellipse_.getFrameRect();
}

void aleksandrov::Circle::move(const point_t& centerPoint)
{
  ellipse_.move(centerPoint);
}

void aleksandrov::Circle::move(double dx, double dy)
{
  ellipse_.move(dx, dy);
}

void aleksandrov::Circle::unsafeScale(double k)
{
  ellipse_.unsafeScale(k);
}

