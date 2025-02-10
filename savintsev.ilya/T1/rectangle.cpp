#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

savintsev::Rectangle::Rectangle(point_t lhs, point_t rhs):
  stay_(lhs, rhs, {lhs.x, rhs.y}, {rhs.x, lhs.y}),
  lay_(lhs, rhs, {rhs.x, lhs.y}, {lhs.x, rhs.y})
{
  if (lhs.x >= rhs.x || lhs.y >= rhs.y)
  {
    throw std::invalid_argument("ERROR: Invalid argumets for Rectangle");
  }
}

double savintsev::Rectangle::getArea() const
{
  return stay_.getArea() + lay_.getArea();
}

savintsev::rectangle_t savintsev::Rectangle::getFrameRect() const
{
  return stay_.getFrameRect();
}

void savintsev::Rectangle::move(point_t p)
{
  stay_.move(p);
  lay_.move(p);
}

void savintsev::Rectangle::move(double x, double y)
{
  stay_.move(x, y);
  lay_.move(x, y);
}

savintsev::Shape * savintsev::Rectangle::clone() const
{
  return new Rectangle(*this);
}

void savintsev::Rectangle::unsafeScale(double k) noexcept
{
  stay_.scale(k);
  lay_.scale(k);
}
