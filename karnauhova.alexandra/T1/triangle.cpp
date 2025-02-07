#include "triangle.hpp"
#include <cmath>
#include <stdexcept>
#include "point.hpp"
namespace
{
  void scale_for(karnauhova::point_t& a, const karnauhova::point_t& b, double k)
  {
    a.x = b.x - (b.x - a.x) * k;
    a.y = b.y - (b.y - a.y) * k;
  }
}
karnauhova::Triangle::Triangle(const point_t& x1, const point_t& x2, const point_t& x3):
  x1_(x1),
  x2_(x2),
  x3_(x3)
{
  double len_1 = getDistance(x1_, x2_);
  double len_2 = getDistance(x2_, x3_);
  double len_3 = getDistance(x1_, x3_);
  if (!(len_1 < (len_2 + len_3) && len_2 < (len_1 + len_3) && len_3 < (len_2 + len_1)))
  {
    throw std::logic_error("It's not a triangle");
  }
}

double karnauhova::Triangle::getArea() const
{
  return std::abs(((x1_.x * (x2_.y - x3_.y) +  x2_.x * (x3_.y - x1_.y) + x3_.x * (x1_.y - x2_.y))) / 2.0);
}

karnauhova::rectangle_t karnauhova::Triangle::getFrameRect() const
{
  double x_max = std::fmax(std::fmax(x1_.x, x2_.x), x3_.x);
  double x_min = std::fmin(std::fmin(x1_.x, x2_.x), x3_.x);
  double y_max = std::fmax(std::fmax(x1_.y, x2_.y), x3_.y);
  double y_min = std::fmin(std::fmin(x1_.y, x2_.y), x3_.y);
  double width = x_max - x_min;
  double height = y_max - y_min;
  point_t pos {x_min + (width / 2), y_min + (height / 2)};
  rectangle_t rect{width, height, pos};
  return rect;
}

void karnauhova::Triangle::move(double x, double y)
{
  x1_.x += x;
  x1_.y += y;
  x3_.x += x;
  x3_.y += y;
  x2_.x += x;
  x2_.y += y;
}

void karnauhova::Triangle::move(const point_t& t)
{
  point_t centr = getFrameRect().pos;
  double shift_x = (t.x - centr.x);
  double shift_y = (t.y - centr.y);
  move(shift_x, shift_y);
}

void karnauhova::Triangle::scale(double k)
{
  point_t t = getFrameRect().pos;
  scale_for(x1_, t, k);
  scale_for(x2_, t, k);
  scale_for(x3_, t, k);
}

karnauhova::Shape* karnauhova::Triangle::clone() const
{
  return new Triangle(*this);
}
