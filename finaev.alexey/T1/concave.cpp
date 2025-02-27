#include "concave.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "base-types.hpp"

namespace
{
  bool operator ==(const finaev::point_t a, const finaev::point_t b)
  {
    return ((a.x == b.x) && (a.y == b.y));
  }

  double len(const finaev::point_t a, const finaev::point_t b)
  {
    return std::sqrt(std::pow((a.x - b.x), 2) + std::pow((a.y - b.y), 2));
  }

  finaev::Rectangle createRect(finaev::point_t f, finaev::point_t s, finaev::point_t i)
  {
    finaev::point_t rightUp = { std::max(f.x, std::max(s.x, i.x)), std::max(f.y, std::max(s.y, i.y)) };
    finaev::point_t leftDown = { std::min(f.x, std::min(s.x, i.x)), std::min(f.y, std::min(s.y, i.y)) };
    return { leftDown, rightUp };
  }

  double areaOnePart(finaev::point_t f, finaev::point_t s, finaev::point_t i)
  {
    double a = len(f, s);
    double b = len(s, i);
    double c = len(f, i);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
  }
}

finaev::Concave::Concave(point_t f, point_t s, point_t t, point_t i):
  first_(createRect(f, s, i)),
  second_(createRect(f, t, i)),
  first_area_(areaOnePart(f, s, i)),
  second_area_(areaOnePart(f, t, i))
{
  if (f == s || f == t || f == i || s == t || s == i || t == i)
  {
    throw std::invalid_argument("uncorrect coordinates");
  }
  else if (((i.x == f.x) && (i.x == s.x)) || ((i.x == t.x) && (i.x == s.x)))
  {
    throw std::invalid_argument("uncorrect coordinates");
  }
  else if (((i.x == f.x) && (i.x == t.x)) || ((i.y == t.y) && (i.y == s.y)))
  {
    throw std::invalid_argument("uncorrect coordinates");
  }
  else if (((i.y == f.y) && (i.x == t.x)) || ((i.y == f.y) && (i.y == s.y)))
  {
    throw std::invalid_argument("uncorrect coordinates");
  }
  else if (len(f, s) + len(f, t) <= len(s, t))
  {
    throw std::invalid_argument("uncorrect coordinates");
  }
  else if (len(s, t) + len(f, t) <= len(f, s))
  {
    throw std::invalid_argument("uncorrect coordinates");
  }
  else if (len(f, s) + len(s, t) <= len(f, t))
  {
    throw std::invalid_argument("uncorrect coordinates");
  }
}

double finaev::Concave::getArea() const
{
  return first_area_ + second_area_;
}

finaev::rectangle_t finaev::Concave::getFrameRect() const
{
  double leftXfirst = first_.getFrameRect().pos.x - first_.getFrameRect().width / 2;
  double leftYfirst = first_.getFrameRect().pos.y - first_.getFrameRect().height / 2;
  double leftXsecond = second_.getFrameRect().pos.x - second_.getFrameRect().width / 2;
  double leftYsecond = second_.getFrameRect().pos.y - second_.getFrameRect().height / 2;
  point_t lDown = { std::min(leftXfirst, leftXsecond), std::min(leftYfirst, leftYsecond) };
  double rightXfirst = first_.getFrameRect().pos.x + first_.getFrameRect().width / 2;
  double rightYfirst = first_.getFrameRect().pos.y + first_.getFrameRect().height / 2;
  double rightXsecond = second_.getFrameRect().pos.x + second_.getFrameRect().width / 2;
  double rightYsecond = second_.getFrameRect().pos.y + second_.getFrameRect().height / 2;
  point_t rUp = { std::max(rightXfirst, rightXsecond), std::max(rightYfirst, rightYsecond) };
  Rectangle rect = { lDown, rUp };
  return rect.getFrameRect();
}

void finaev::Concave::move(double sx, double sy)
{
  first_.move(sx, sy);
  second_.move(sx, sy);
}

void finaev::Concave::move(point_t a)
{
  point_t t = getFrameRect().pos;
  double changeX = a.x - t.x;
  double changeY = a.y - t.y;
  first_.move(changeX, changeY);
  second_.move(changeX, changeY);
}

void finaev::Concave::scale(double k)
{
  first_.scale(k);
  second_.scale(k);
  first_area_ *= k * k;
  second_area_ *= k * k;
}
