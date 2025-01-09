#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>

void searchInArray(const double *x, double &a, double &b, size_t k)
{
  if (k >= 1)
  {
    double max = x[0];
    double min = x[0];
    for (size_t i = 0; i < k; ++i)
    {
      if (x[i] > max)
      {
        max = x[i];
      }
      if (x[i] < min)
      {
        min = x[i];
      }
    }
    a = min;
    b = max;
  }
}

void getCoordsOfIntersection(const abramov::point_t *points, double &x, double &y)
{
  const abramov::point_t A = points[0];
  const abramov::point_t B = points[1];
  const abramov::point_t C = points[2];
  const abramov::point_t D = points[3];
  const double k1 = (B.y - A.y) / (B.x - A.x);
  const double b1 = A.y - A.x * k1;
  const double k2 = (D.y - C.y) / (D.x - C.x);
  const double b2 = C.y - C.x * k2;
  if (k1 == k2)
  {
    throw std::logic_error("There is no center\n");
  }
  x = (b2 - b1) / (k1 - k2);
  y = k1 * x + b1;
  if (x == A.x || x == B.x || x == C.x || x == D.x)
  {
    throw std::logic_error("There is no center\n");
  }
  constexpr size_t k = 4;
  double xs[k] = {A.x, B.x, C.x, D.x};
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

double getTriangleArea(abramov::point_t A, abramov::point_t B, abramov::point_t O)
{
  const double a = getLength(A, B);
  const double b = getLength(B, O);
  const double c = getLength(O, A);
  const double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

void abramov::createCQs(point_t p1, point_t p2, ComplexQuad &cq1, ComplexQuad &cq2, ComplexQuad &cq3, ComplexQuad &cq4)
{
  const double x1 = p1.x;
  const double x2 = p2.x;
  const double y1 = p1.y;
  const double y2 = p2.y;
  const point_t a{x1, y2};
  const point_t b{x2, y1};
  if (x2 - x1 >= y2 - y1)
  {
    const double x3 = (x1 + x2) / 2;
    const point_t c{x3, y2};
    const point_t d{x3, y1};
    cq1 = ComplexQuad(p1, c, d, a);
    cq2 = ComplexQuad(a, d, p1, c);
    cq3 = ComplexQuad(d, p2, b, c);
    cq4 = ComplexQuad(c, b, d, p2);
  }
  else
  {
    const double y3 = (y1 + y2) / 2;
    const point_t c{x2, y3};
    const point_t d{x1, y3};
    cq1 = ComplexQuad(a, c, p2, d);
    cq2 = ComplexQuad(d, p2, a, c);
    cq3 = ComplexQuad(p1, c, b, d);
    cq4 = ComplexQuad(p1, c, d, b);
  }
}

abramov::ComplexQuad::ComplexQuad():
  points{{0.0, 0.0}, {10.0, 10.0}, {2.0, 0.0}, {0.0, 3.0}}
{}

abramov::ComplexQuad::ComplexQuad(point_t A, point_t B, point_t C, point_t D):
  points{A, B, C, D}
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
  const point_t A = points[0];
  const point_t B = points[1];
  const point_t C = points[2];
  const point_t D = points[3];
  double x[k] = {A.x, B.x, C.x, D.x};
  double y[k] = {A.y, B.y, C.y, D.y};
  double max_x = 0;
  double min_x = 0;
  double max_y = 0;
  double min_y = 0;
  searchInArray(x, min_x, max_x, k);
  searchInArray(y, min_y, max_y, k);
  point_t pos{(max_x + min_x) / 2, (max_y + min_y) / 2};
  rectangle_t frame_rect{max_x - min_x, max_y - min_y, pos};
  return frame_rect;
}

abramov::point_t abramov::ComplexQuad::getCenterComplexQuad() const
{
  double x = 0;
  double y = 0;
  getCoordsOfIntersection(points, x, y);
  point_t center{x, y};
  return center;
}

void abramov::ComplexQuad::move(point_t p)
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
  if (k <= 0)
  {
    throw std::logic_error("Wrong scale coef\n");
  }
  else
  {
    const point_t O = getCenterComplexQuad();
    const double dk = k - 1;
    const double ox = O.x;
    const double oy = O.y;
    constexpr size_t k = 4;
    for (size_t i = 0; i < k; ++i)
    {
      double dx = -1 * (ox - points[i].x) * dk;
      double dy = -1 * (oy - points[i].y) * dk;
      changePointCoords(points[i], dx, dy);
    }
  }
}

abramov::ComplexQuad *abramov::ComplexQuad::clone() const
{
  return new ComplexQuad(*this);
}

abramov::point_t abramov::ComplexQuad::getA() const
{
  return points[0];
}

abramov::point_t abramov::ComplexQuad::getB() const
{
  return points[1];
}

abramov::point_t abramov::ComplexQuad::getC() const
{
  return points[2];
}

abramov::point_t abramov::ComplexQuad::getD() const
{
  return points[3];
}
