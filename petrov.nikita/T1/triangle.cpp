#include "triangle.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "geometric_calculations.hpp"

petrov::Triangle::Triangle(const point_t & p1, const point_t & p2, const point_t & p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  double a = calculateDistBtwPoints(p1_, p2_);
  double b = calculateDistBtwPoints(p3_, p2_);
  double c = calculateDistBtwPoints(p1_, p3_);
  if (a + b <= c || a + c <= b || b + c <= a)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description");
  }
}

double petrov::Triangle::getArea() const
{
  double a = calculateDistBtwPoints(p1_, p2_);
  double b = calculateDistBtwPoints(p3_, p2_);
  double c = calculateDistBtwPoints(p1_, p3_);
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

petrov::rectangle_t petrov::Triangle::getFrameRect() const
{
  double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
  double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
  double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
  double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
  double width = xmax - xmin;
  double height = ymax - ymin;
  point_t pos = { ((xmin + xmax) / 2.0), ((ymin + ymax) / 2.0) };
  return { width, height, pos };
}

void petrov::Triangle::move(const point_t & concrete_point)
{
  point_t pos = getFrameRect().pos;
  double dx = concrete_point.x - pos.x;
  double dy = concrete_point.y - pos.y;
  this->move(dx, dy);
}

void petrov::Triangle::move(double dx, double dy)
{
  point_t * points[3] = { &p1_, &p2_, &p3_ };
  changeCoordinates(points, 3, dx, dy);
}

void petrov::Triangle::scale(double k)
{
  point_t * points[3] = { &p1_, &p2_, &p3_ };
  point_t pos = getFrameRect().pos;
  changeCoordinatesDueToScaling(points, pos, 3, k);
}

petrov::Shape * petrov::Triangle::clone() const
{
  return new Triangle(*this);
}
