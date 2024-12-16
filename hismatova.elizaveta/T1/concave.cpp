#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>

hismatova::concave::concave(const point_t &a, const point_t &b, const point_t &c, const point_t &d):
  a_(a),
  b_(b),
  c_(c),
  d_(d)
{}
double hismatova::concave::getArea() const
{
  double triangle1Area = 0.5 * std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y));
  double triangle2Area = 0.5 * std::abs(c_.x * (d_.y - b_.y) + d_.x * (b_.y - c_.y) + b_.x * (c_.y - d_.y));
  return triangle1Area - triangle2Area;
}
hismatova::rectangle_t hismatova::concave::getFrameRect() const
{
  double minX = std::min({a_.x, b_.x, c_.x, d_.x});
  double maxX = std::max({a_.x, b_.x, c_.x, d_.x});
  double minY = std::min({a_.y, b_.y, c_.y, d_.y});
  double maxY = std::max({a_.y, b_.y, c_.y, d_.y});
  return {maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2}};
}
void hismatova::concave::move(const point_t &newPos)
{
  double dx = newPos.x - getFrameRect().pos.x;
  double dy = newPos.y - getFrameRect().pos.y;
  move(dx, dy);
}
void hismatova::concave::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
  d_.x += dx;
  d_.y += dy;
}
void hismatova::concave::scale(double index)
{
  if (index <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive.");
  }
  hismatova::point_t center = getFrameRect().pos;
  a_.x = center.x + (a_.x - center.x) * index;
  a_.y = center.y + (a_.y - center.y) * index;
  b_.x = center.x + (b_.x - center.x) * index;
  b_.y = center.y + (b_.y - center.y) * index;
  c_.x = center.x + (c_.x - center.x) * index;
  c_.y = center.y + (c_.y - center.y) * index;
  d_.x = center.x + (d_.x - center.x) * index;
  d_.y = center.y + (d_.y - center.y) * index;
}
