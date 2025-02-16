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
  
  bool Sharp(finaev::point_t f, finaev::point_t s, finaev::point_t t)
  {
    if ((f.x > s.x && f.x > t.x) || (f.x < s.x && f.x < t.x))
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
 


finaev::Concave::Concave(point_t f, point_t s, point_t t, point_t i):
  first(createRect(f, s, i)),
  second(createRect(f, t, i)),
  first_area_(areaOnePart(f, s, i)),
  second_area_(areaOnePart(f, t, i)),
  isSharp(Sharp(f, s, t))
{
  if (f == s || f == t || f == i || s == t || s == i || t == i)
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (((i.x == f.x) && (i.x == s.x)) || ((i.x == t.x) && (i.x == s.x)))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (((i.x == f.x) && (i.x == t.x)) || ((i.y == t.y) && (i.y == s.y)))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (((i.y == f.y) && (i.x == t.x)) || ((i.y == f.y) && (i.y == s.y)))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (len(f, s) + len(f, t) <= len(s, t))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (len(s, t) + len(f, t) <= len(f, s))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (len(f, s) + len(s, t) <= len(f, t))
  {
    throw std::logic_error("uncorrect coordinates");
  }
}

double finaev::Concave::getArea() const
{
    return first_area_ + second_area_;
}

finaev::rectangle_t finaev::Concave::getFrameRect() const
{
  double leftXfirst = first.getFrameRect().pos.x - first.getFrameRect().width / 2;
  double leftYfirst = first.getFrameRect().pos.y - first.getFrameRect().height / 2;
  double leftXsecond = second.getFrameRect().pos.x - second.getFrameRect().width / 2;
  double leftYsecond = second.getFrameRect().pos.y - second.getFrameRect().height / 2;
  point_t lDown = {std::min(leftXfirst, leftXsecond), std::min(leftYfirst, leftYsecond)};
  double rightXfirst = first.getFrameRect().pos.x + first.getFrameRect().width / 2;
  double rightYfirst = first.getFrameRect().pos.y + first.getFrameRect().height / 2;
  double rightXsecond = second.getFrameRect().pos.x + second.getFrameRect().width / 2;
  double rightYsecond = second.getFrameRect().pos.y + second.getFrameRect().height / 2;
  point_t rUp = {std::max(rightXfirst, rightXsecond), std::max(rightYfirst, rightYsecond)};
  Rectangle rect = {lDown, rUp};
  return rect.getFrameRect();
}

void finaev::Concave::move(double sx, double sy)
{
  first.move(sx, sy);
  second.move(sx, sy);
}

void finaev::Concave::move(point_t a)
{
  point_t t = getFrameRect().pos;
  double changeX = a.x - t.x;
  double changeY = a.y - t.y;
  first.move(changeX, changeY);
  second.move(changeX, changeY);
}

void finaev::Concave::scale(double k)
{
  first.scale(k);
  second.scale(k);
  first_area_ *= k;
  second_area_ *= k;
}
