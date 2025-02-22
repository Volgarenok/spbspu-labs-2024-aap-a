#include "parallelogram.hpp"

#include <cmath>
#include <istream>
#include <stdexcept>

#include <common_utils.hpp>

zholobov::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3):
  pos_({(p1.x + p3.x) / 2.0, (p1.y + p3.y) / 2.0}),
  p1_({p1.x - pos_.x, p1.y - pos_.y}),
  p2_({p2.x - pos_.x, p2.y - pos_.y})
{
  if (!(((p1.y == p2.y) && (p1.y != p3.y)) || ((p2.y == p3.y) && (p1.y != p2.y)))) {
    throw std::invalid_argument("Error in PARALLELOGRAM parameters");
  }
}

double zholobov::Parallelogram::getArea() const
{
  double base = (p1_.y == p2_.y) ? (p2_.x - p1_.x) : (2.0 * pos_.x - p2_.x - p1_.x);
  return std::abs(base * p1_.y * 2.0);
}

zholobov::rectangle_t zholobov::Parallelogram::getFrameRect() const
{
  return rectangle_t{std::abs(p1_.x) * 2.0, std::abs(p1_.y) * 2.0, pos_};
}

void zholobov::Parallelogram::move(point_t p)
{
  pos_ = p;
}

void zholobov::Parallelogram::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void zholobov::Parallelogram::scale_no_check(double k)
{
  p1_.x *= k;
  p1_.y *= k;
  p2_.x *= k;
  p2_.y *= k;
}

zholobov::Shape* zholobov::Parallelogram::clone() const
{
  return new Parallelogram(*this);
}

zholobov::Parallelogram* zholobov::Parallelogram::create(std::istream& in)
{
  double params[6];
  read_array(params, 6, in);
  return new Parallelogram(
    point_t{params[0], params[1]},
    point_t{params[2], params[3]},
    point_t{params[4], params[5]});
}
