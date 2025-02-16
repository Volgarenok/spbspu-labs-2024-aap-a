#include "triangle.hpp"
#include <algorithm>
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Triangle::Triangle(point_t one, point_t two, point_t three):
  one_(one),
  two_(two),
  three_(three)
{}

double asafov::Triangle::getArea() const
{
  double sidea = std::pow(std::pow((one_.x - two_.x), 2.0) + std::pow((one_.y - two_.y), 2.0), 0.5);
  double sideb = std::pow(std::pow((two_.x - three_.x), 2.0) + std::pow((two_.y - three_.y), 2.0), 0.5);
  double sidec = std::pow(std::pow((one_.x - three_.x), 2.0) + std::pow((one_.y - three_.y), 2.0), 0.5);
  return std::pow(((sidea + sideb + sidec) * (sidea + sideb - sidec) * (sidea - sideb + sidec) * (sideb + sidec - sidea) / 16.0), 0.5);
}

rectangle_t asafov::Triangle::getFrameRect() const
{
  rectangle_t rect;
  rect.height = std::max({one_.y, two_.y, three_.y}) - std::min({one_.y, two_.y, three_.y});
  rect.width = std::max({one_.x, two_.x, three_.x}) - std::min({one_.x, two_.x, three_.x});
  rect.pos.x = std::min({one_.x, two_.x, three_.x}) + rect.width / 2.0;
  rect.pos.y = std::min({one_.y, two_.y, three_.y}) + rect.height / 2.0;
  return rect;
}

void asafov::Triangle::move(double x, double y)
{
  one_.x += x;
  one_.y += y;
  two_.x += x;
  two_.y += y;
  three_.x += x;
  three_.y += y;
}

void asafov::Triangle::move(point_t pos)
{
  rectangle_t rect = getFrameRect();
  one_.x += pos.x - rect.pos.x;
  one_.y += pos.y - rect.pos.y;
  two_.x += pos.x - rect.pos.x;
  two_.y += pos.y - rect.pos.y;
  three_.x += pos.x - rect.pos.x;
  three_.y += pos.y - rect.pos.y;
}

void asafov::Triangle::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  one_.x += (one_.x - rect.pos.x) * (scale - 1);
  one_.y += (one_.y - rect.pos.y) * (scale - 1);
  two_.x += (two_.x - rect.pos.x) * (scale - 1);
  two_.y += (two_.y - rect.pos.y) * (scale - 1);
  three_.x += (three_.x - rect.pos.x) * (scale - 1);
  three_.y += (three_.y - rect.pos.y) * (scale - 1);
}
