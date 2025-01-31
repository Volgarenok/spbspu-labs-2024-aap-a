#include "rectangle.hpp"
#include <stdexcept>
#include "geometric_calculations.hpp"

petrov::Rectangle::Rectangle(const petrov::point_t & p1, const petrov::point_t & p2):
  p1_(p1),
  p2_(p2)
{
  if (p1_.x >= p2_.x || p1_.y >= p2_.y)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description\n");
  }
}

double petrov::Rectangle::getArea() const
{
  return (p2_.x - p1_.x) * (p2_.y - p1_.y);
}

petrov::rectangle_t petrov::Rectangle::getFrameRect() const
{
  double width = p2_.x - p1_.x;
  double height = p2_.y - p1_.y;
  point_t pos = { ((p1_.x + p2_.x) / 2.0), ((p1_.y + p2_.y) / 2.0) };
  return { width, height, pos };
}

void petrov::Rectangle::move(const petrov::point_t & concrete_point)
{
  point_t pos = getFrameRect().pos;
  double dx = concrete_point.x - pos.x;
  double dy = concrete_point.y - pos.y;
  this->move(dx, dy);
}

void petrov::Rectangle::move(double dx, double dy)
{
  petrov::point_t * points[2] = { &p1_, &p2_ };
  petrov::changeCoordinates(points, 2, dx, dy);
}

void petrov::Rectangle::scale(double k)
{
  petrov::point_t * points[2] = { &p1_, &p2_ };
  petrov::point_t pos = getFrameRect().pos;
  changeCoordinatesDueToScaling(points, pos, 2, k);
}

petrov::Shape * petrov::Rectangle::clone() const
{
  return new Rectangle(*this);
}
