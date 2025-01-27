#include "triangle.hpp"
#include <cmath>
#include <stdexcept>
#include "point.hpp"
karnauhova::Triangle::Triangle(point_t x1, point_t x2, point_t x3):
  x1_(x1),
  x2_(x2),
  x3_(x3)
{
  double len_1 = karnauhova::getDistance(x1_, x2_);
  double len_2 = karnauhova::getDistance(x2_, x3_);
  double len_3 = karnauhova::getDistance(x1_, x3_);
  if (!(len_1 < (len_2 + len_3) && len_2 < (len_1 + len_3) && len_3 < (len_2 + len_1)))
  {
    throw std::logic_error("It's not a triangle");
  }
}

double karnauhova::Triangle::getArea() const
{
  double len_1 = karnauhova::getDistance(x1_, x2_);
  double len_2 = karnauhova::getDistance(x2_, x3_);
  double len_3 = karnauhova::getDistance(x1_, x3_);
  double p = (len_1 + len_2 + len_3)/2;
  return std::sqrt(p * (p - len_1) * (p - len_2) * (p - len_3));
}

karnauhova::rectangle_t karnauhova::Triangle::getFrameRect() const
{
  double x_max = std::fmax(std::fmax(x1_.x, x2_.x), x3_.x);
  double x_min = std::fmin(std::fmin(x1_.x, x2_.x), x3_.x);
  double y_max = std::fmax(std::fmax(x1_.y, x2_.y), x3_.y);
  double y_min = std::fmin(std::fmin(x1_.y, x2_.y), x3_.y);
  rectangle_t rect;
  rect.width = x_max - x_min;
  rect.height = y_max - y_min;
  rect.pos.x = x_min + (rect.width / 2);
  rect.pos.y = y_min + (rect.height / 2);
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

void karnauhova::Triangle::move(point_t t)
{
  point_t centr = getFrameRect().pos;
  double shift_x = (t.x - centr.x);
  double shift_y = (t.y - centr.y);
  move(shift_x, shift_y);
}

void karnauhova::Triangle::scale(double k)
{
  point_t t = getFrameRect().pos;
  double distance_x1 = x1_.x - t.x;
  double distance_x2 = x2_.x - t.x;
  double distance_x3 = x3_.x - t.x;
  double distance_y1 = x1_.y - t.y;
  double distance_y2 = x2_.y - t.y;
  double distance_y3 = x3_.y - t.y;
  x1_.x = t.x + distance_x1 * k;
  x2_.x = t.x + distance_x2 * k;
  x3_.x = t.x + distance_x3 * k;
  x1_.y = t.y + distance_y1 * k;
  x2_.y = t.y + distance_y2 * k;
  x3_.y = t.y + distance_y3 * k;
}
