#include "concave.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "base-types.hpp"

bool finaev::operator ==(const point_t a, const point_t b)
{
  return ((a.x == b.x) && (a.y == b.y));
}

double finaev::len(const point_t a, const point_t b)
{
  return std::sqrt(std::pow((a.x - b.x), 2) + std::pow((a.y - b.y), 2));
}

finaev::Concave::Concave(point_t f, point_t s, point_t t, point_t i):
  first(f),
  second(s),
  third(t),
  internal(i)
{
  if (first == second || first == third || first == internal || second == third || second == internal || third == internal)
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (((internal.x == first.x) && (internal.x == second.x)) || ((internal.x == third.x) && (internal.x == second.x)))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (((internal.x == first.x) && (internal.x == third.x)) || ((internal.y == third.y) && (internal.y == second.y)))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (((internal.y == first.y) && (internal.x == third.x)) || ((internal.y == first.y) && (internal.y == second.y)))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (len(first, second) + len(first, third) <= len(second, third))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (len(second, third) + len(first, third) <= len(first, second))
  {
    throw std::logic_error("uncorrect coordinates");
  }
  else if (len(first, second) + len(second, third) <= len(first, third))
  {
    throw std::logic_error("uncorrect coordinates");
  }
}

double finaev::Concave::getArea() const
{
  double a1 = len(first, second);
  double b1 = len(first, third);
  double c = len(second, third);
  double p1 = (a1 + b1 + c) / 2;
  double s1 = std::sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c));
  double a2 = len(second, internal);
  double b2 = len(third, internal);
  double p2 = (a2 + b2 + c) / 2;
  double s2 = std::sqrt(p2 * (p2 - a2) * (p2 - b2) * (p2 - c));
  return s1 - s2;
}

finaev::rectangle_t finaev::Concave::getFrameRect() const
{
  double width = std::max(first.x, std::max(second.x, third.x)) - std::min(first.x, std::min(second.x, third.x));
  double height = std::max(first.y, std::max(second.y, third.y)) - std::min(first.y, std::min(second.y, third.y));
  double x = std::min(first.x, std::min(second.x, third.x)) + (width / 2);
  double y = std::min(first.y, std::min(second.y, third.y)) + (height / 2);
  point_t pos = {x, y};
  rectangle_t a = {pos, width, height};
  return a;
}

void finaev::Concave::move(double sx, double sy)
{
  point_t * point[4] = {&first, &second, &third, &internal};
  double moveX = 0.0;
  double moveY = 0.0;
  for (size_t i = 0; i < 4; i++)
  {
    point_t p = *point[i];
    moveX = p.x + sx;
    moveY = p.y + sy;
    *point[i] = {moveX, moveY};
  }
}

void finaev::Concave::move(point_t a)
{
  double changeX = a.x - internal.x;
  double changeY = a.y - internal.y;
  this->move(changeX, changeY);
}

void finaev::Concave::scale(double k)
{
  double x1 = internal.x - (internal.x * k);
  double y1 = internal.y - (internal.y * k);
  first.x = x1 + (first.x * k);
  first.y = y1 + (first.y * k);
  second.x = x1 + (second.x * k);
  second.y = y1 + (second.y * k);
  third.x = x1 + (third.x * k);
  third.y = y1 + (third.y * k);
}
