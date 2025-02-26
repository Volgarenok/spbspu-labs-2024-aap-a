#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include "triangle.hpp"
#include "getShapeInfo.hpp"

dribas::Diamond::Diamond(point_t a, point_t b, point_t c):
  a_(a, b, c),
  b_(a, a, {c.x - 2 * std::abs(std::abs(b.x) - std::abs(a.x)), c.y}),
  c_(a, {b.x, b.y - 2 * std::abs(std::abs(a.y) - std::abs(c.y))}, {c.x - std::abs(std::abs(b.x) - std::abs(a.x)), c.y}),
  d_(a, {b.x, b.y - 2 * std::abs(std::abs(a.y) - std::abs(c.y))}, c)
{}

double dribas::Diamond::getArea() const
{
  return a_.getArea() * 4.0f;
}

dribas::rectangle_t dribas::Diamond::getFrameRect() const
{
  rectangle_t fremRect = a_.getFrameRect();
  fremRect.width *= 2;
  fremRect.height *= 2;
  return fremRect;
}

void dribas::Diamond::move(double x, double y)
{
  a_.move(x, y);
  b_.move(x, y);
  c_.move(x, y);
  d_.move(x, y);
}

void dribas::Diamond::move(point_t point)
{
  double moveX = point.x - getFrameRect().pos.x;
  double moveY = point.y - getFrameRect().pos.y;
  move(moveX, moveY);
}

void dribas::Diamond::scaleSilent(double ratio)
{
  scaleOne(a_, ratio, getFrameRect().pos);
  scaleOne(b_, ratio, getFrameRect().pos);
  scaleOne(c_, ratio, getFrameRect().pos);
  scaleOne(d_, ratio, getFrameRect().pos);
}

dribas::Shape* dribas::Diamond::clone() const
{
  return new Diamond(*this);
}
