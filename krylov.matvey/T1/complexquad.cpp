#include "complexquad.hpp"
#include <algorithm>
#include <stdexcept>

krylov::Complexquad::Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d):
  t1_(a, b, c),
  t2_(c, d, a),
  t3_(b, c, d),
  t4_(d, a, b)
{
  if (getArea() <= 0)
  {
    throw std::invalid_argument("Invalid complexquad coordinates");
  }
}

double krylov::Complexquad::getArea() const
{
  return t1_.getArea() + t2_.getArea() + t3_.getArea() + t4_.getArea();
}

krylov::rectangle_t krylov::Complexquad::getFrameRect() const
{
  double minX = std::min({t1_.getFrameRect().pos.x, t2_.getFrameRect().pos.x,
                          t3_.getFrameRect().pos.x, t4_.getFrameRect().pos.x});

  double maxX = std::max({t1_.getFrameRect().pos.x, t2_.getFrameRect().pos.x,
                          t3_.getFrameRect().pos.x, t4_.getFrameRect().pos.x});

  double minY = std::min({t1_.getFrameRect().pos.y, t2_.getFrameRect().pos.y,
                          t3_.getFrameRect().pos.y, t4_.getFrameRect().pos.y});

  double maxY = std::max({t1_.getFrameRect().pos.y, t2_.getFrameRect().pos.y,
                          t3_.getFrameRect().pos.y, t4_.getFrameRect().pos.y});

  point_t center = { (minX + maxX) / 2, (minY + maxY) / 2 };
  return { maxX - minX, maxY - minY, center };
}

void krylov::Complexquad::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void krylov::Complexquad::move(double dx, double dy)
{
  t1_.move(dx, dy);
  t2_.move(dx, dy);
  t3_.move(dx, dy);
  t4_.move(dx, dy);
}

void krylov::Complexquad::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }

  t1_.scale(factor);
  t2_.scale(factor);
  t3_.scale(factor);
  t4_.scale(factor);
}
