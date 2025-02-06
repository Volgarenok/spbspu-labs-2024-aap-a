#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>

hismatova::Concave::Concave(const point_t &a, const point_t &b, const point_t &c, const point_t &d):
  a_(a),
  b_(b),
  c_(c),
  d_(d)
{
  double a0 = 0.5 * std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y));
  double a1 = 0.5 * std::abs(d_.x * (b_.y - c_.y) + b_.x * (c_.y - d_.y) + c_.x * (d_.y - b_.y));
  double a2 = 0.5 * std::abs(a_.x * (d_.y - c_.y) + d_.x * (c_.y - a_.y) + c_.x * (a_.y - d_.y));
  double a3 = 0.5 * std::abs(a_.x * (b_.y - d_.y) + b_.x * (d_.y - a_.y) + d_.x * (a_.y - b_.y));
  if (a0 <= 0 || (a0 != a1 + a2 + a3) || a1 <= 0 || a2 <= 0 || a3 <= 0)
  {
    throw std::invalid_argument("concave cannot be built");
  }
}
double hismatova::Concave::getArea() const
{
  double triangle1Area = 0.5 * std::abs(a_.x * (b_.y - c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y));
  double triangle2Area = 0.5 * std::abs(c_.x * (d_.y - b_.y) + d_.x * (b_.y - c_.y) + b_.x * (c_.y - d_.y));
  return triangle1Area - triangle2Area;
}
hismatova::rectangle_t hismatova::Concave::getFrameRect() const
{
  double minX = std::min({a_.x, b_.x, c_.x, d_.x});
  double maxX = std::max({a_.x, b_.x, c_.x, d_.x});
  double minY = std::min({a_.y, b_.y, c_.y, d_.y});
  double maxY = std::max({a_.y, b_.y, c_.y, d_.y});
  return {maxY - minY, maxX - minX, {(minX + maxX) / 2.0, (minY + maxY) / 2.0}};
}
void hismatova::Concave::move(const point_t &newPos)
{
  double dx = newPos.x - this->getFrameRect().pos.x;
  double dy = newPos.y - this->getFrameRect().pos.y;
  move(dx, dy);
}
void hismatova::Concave::movePoint(point_t& point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
}
void hismatova::Concave::move(double dx, double dy)
{
  movePoint(a_, dx, dy);
  movePoint(b_, dx, dy);
  movePoint(c_, dx, dy);
  movePoint(d_, dx, dy);
}
void hismatova::Concave::scalePoint(point_t& point, const point_t& center, double index)
{
  point.x = center.x + (point.x - center.x) * index;
  point.y = center.y + (point.y - center.y) * index;
}
void hismatova::Concave::scale(double index)
{
  point_t center = this->getFrameRect().pos;
  scalePoint(a_, center, index);
  scalePoint(b_, center, index);
  scalePoint(c_, center, index);
  scalePoint(d_, center, index);
}
