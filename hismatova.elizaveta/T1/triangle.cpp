#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

hismatova::Triangle::Triangle(const point_t &a, const point_t &b, const point_t &c):
  a_(a),
  b_(b),
  c_(c)
{
  if (0.5 * std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y)) <= 0)
  {
    throw std::invalid_argument("triangle cannot be built");
  }
}
double hismatova::Triangle::getArea() const
{
  return 0.5 * std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y));
}
hismatova::rectangle_t hismatova::Triangle::getFrameRect() const
{
  double minX = std::min({a_.x, b_.x, c_.x});
  double maxX = std::max({a_.x, b_.x, c_.x});
  double minY = std::min({a_.y, b_.y, c_.y});
  double maxY = std::max({a_.y, b_.y, c_.y});
  return {maxY - minY, maxX - minX, {(minX + maxX) / 2.0, (minY + maxY) / 2.0}};
}
void hismatova::Triangle::move(const point_t &newPos)
{
  point_t centroid = this->getCentroid();
  double dx = newPos.x - centroid.x;
  double dy = newPos.y - centroid.y;
  move(dx, dy);
}
void hismatova::Triangle::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}
void hismatova::Triangle::scale(double index)
{
  point_t centroid = this->getCentroid();
  a_.x = centroid.x + (a_.x - centroid.x) * index;
  a_.y = centroid.y + (a_.y - centroid.y) * index;
  b_.x = centroid.x + (b_.x - centroid.x) * index;
  b_.y = centroid.y + (b_.y - centroid.y) * index;
  c_.x = centroid.x + (c_.x - centroid.x) * index;
  c_.y = centroid.y + (c_.y - centroid.y) * index;
}
hismatova::point_t hismatova::Triangle::getCentroid() const
{
  return {(a_.x + b_.x + c_.x) / 3.0, (a_.y + b_.y + c_.y) / 3.0};
}
