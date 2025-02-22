#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>

namespace
{
  void searchInArray(const double *x, double &a, double &b, size_t k)
  {
    if (k < 2)
    {
      throw std::logic_error("There is not enough elements\n");
    }
    a = x[0];
    b = x[0];
    for (size_t i = 0; i < k; ++i)
    {
      if (x[i] > b)
      {
        b = x[i];
      }
      if (x[i] < a)
      {
        a = x[i];
      }
    }
  }

  void getCoordsOfIntersection(const abramov::point_t *points, double &x, double &y)
  {
    const abramov::point_t a = points[0];
    const abramov::point_t b = points[1];
    const abramov::point_t c = points[2];
    const abramov::point_t d = points[3];
    const double k1 = (b.y - a.y) / (b.x - a.x);
    const double b1 = a.y - a.x * k1;
    const double k2 = (d.y - c.y) / (d.x - c.x);
    const double b2 = c.y - c.x * k2;
    if (k1 == k2)
    {
      throw std::logic_error("There is no center\n");
    }
    x = (b2 - b1) / (k1 - k2);
    y = k1 * x + b1;
    if (x == a.x || x == b.x || x == c.x || x == d.x)
    {
      throw std::logic_error("There is no center\n");
    }
    constexpr size_t k = 4;
    double xs[k] = { a.x, b.x, c.x, d.x };
    size_t count = 0;
    for (size_t i = 0; i < k; ++i)
    {
      if (x > xs[i])
      {
        ++count;
      }
    }
    if (count != 2)
    {
      throw std::logic_error("There is no center\n");
    }
  }

  double getTriangleArea(abramov::point_t p1, abramov::point_t p2, abramov::point_t o)
  {
    const double a = getLength(p1, p2);
    const double b = getLength(p2, o);
    const double c = getLength(o, p1);
    const double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
  }
}

abramov::ComplexQuad *abramov::createCQs(const point_t &p1, const point_t &p2)
{
  const double x1 = p1.x;
  const double x2 = p2.x;
  const double y1 = p1.y;
  const double y2 = p2.y;
  const point_t a{ x1, y2 };
  const point_t b{ x2, y1 };
  constexpr size_t k = 4;
  if (2 * (x2 - x1) >= y2 - y1)
  {
    const double x3 = (x1 + x2) / 2;
    const point_t c{x3, y2};
    const point_t d{x3, y1};
    ComplexQuad cq1 = ComplexQuad(p1, c, d, a);
    ComplexQuad cq2 = ComplexQuad(a, d, p1, c);
    ComplexQuad cq3 = ComplexQuad(d, p2, b, c);
    ComplexQuad cq4 = ComplexQuad(c, b, d, p2);
    ComplexQuad *cqs = new ComplexQuad[k]{ cq1, cq2, cq3, cq4 };
    return cqs;
  }
  else
  {
    const double y3 = (y1 + y2) / 2;
    const point_t c{x2, y3};
    const point_t d{x1, y3};
    ComplexQuad cq1 = ComplexQuad(a, c, p2, d);
    ComplexQuad cq2 = ComplexQuad(d, p2, a, c);
    ComplexQuad cq3 = ComplexQuad(p1, c, b, d);
    ComplexQuad cq4 = ComplexQuad(p1, c, d, b);
    ComplexQuad *cqs = new ComplexQuad[k]{ cq1, cq2, cq3, cq4 };
    return cqs;
  }
}

abramov::ComplexQuad::ComplexQuad(const point_t &a, const point_t &b, const point_t &c, const point_t &d):
  points{ a, b, c, d }
{
  double x = 0;
  double y = 0;
  getCoordsOfIntersection(points, x, y);
}

double abramov::ComplexQuad::getArea() const noexcept
{
  const point_t center = getCenterComplexQuad();
  return getTriangleArea(points[0], points[3], center) + getTriangleArea(points[1], points[2], center);
}

abramov::rectangle_t abramov::ComplexQuad::getFrameRect() const noexcept
{
  constexpr size_t k = 4;
  const point_t a = points[0];
  const point_t b = points[1];
  const point_t c = points[2];
  const point_t d = points[3];
  double x[k] = { a.x, b.x, c.x, d.x };
  double y[k] = { a.y, b.y, c.y, d.y };
  double max_x = 0;
  double min_x = 0;
  double max_y = 0;
  double min_y = 0;
  searchInArray(x, min_x, max_x, k);
  searchInArray(y, min_y, max_y, k);
  point_t pos{ (max_x + min_x) / 2, (max_y + min_y) / 2 };
  rectangle_t frame_rect{ max_x - min_x, max_y - min_y, pos };
  return frame_rect;
}

abramov::point_t abramov::ComplexQuad::getCenterComplexQuad() const
{
  double x = 0;
  double y = 0;
  getCoordsOfIntersection(points, x, y);
  point_t center{ x, y };
  return center;
}

void abramov::ComplexQuad::move(const point_t &p)
{
  const point_t center = getCenterComplexQuad();
  const double dx = p.x - center.x;
  const double dy = p.y - center.y;
  move(dx, dy);
}

void abramov::ComplexQuad::move(double dx, double dy)
{
  constexpr size_t k = 4;
  for (size_t i = 0; i < k; ++i)
  {
    changePointCoords(points[i], dx, dy);
  }
}

void abramov::ComplexQuad::scale(double k)
{
  const point_t o = getCenterComplexQuad();
  const double dk = k - 1;
  const double ox = o.x;
  const double oy = o.y;
  for (size_t i = 0; i < 4; ++i)
  {
    double dx = -1 * (ox - points[i].x) * dk;
    double dy = -1 * (oy - points[i].y) * dk;
    changePointCoords(points[i], dx, dy);
  }
}

abramov::ComplexQuad *abramov::ComplexQuad::clone() const
{
  return new ComplexQuad(*this);
}
