#include "rectangle.hpp"
#include <stdexcept>
#include <algorithm>
#include "shape.hpp"
#include "base-types.hpp"

namespace
{
  const abramov::point_t A{-1.0, -1.0};
  const abramov::point_t B{-1.0, 1.0};
  const abramov::point_t C{1.0, 1.0};
  const abramov::point_t D{1.0, -1.0};
  const abramov::point_t E{0.0, 1.0};
  const abramov::point_t F{0.0, -1.0};
  abramov::ComplexQuad cq1 = abramov::ComplexQuad(A, E, F, B);
  abramov::ComplexQuad cq2 = abramov::ComplexQuad(B, F, A, E);
  abramov::ComplexQuad cq3 = abramov::ComplexQuad(F, C, D, E);
  abramov::ComplexQuad cq4 = abramov::ComplexQuad(E, D, F, C);
  constexpr size_t k = 4;
  abramov::ComplexQuad basicCQs[k] = { cq1, cq2, cq3, cq4 };
}

abramov::Rectangle::Rectangle(point_t p1, point_t p2):
  cmplxqds(basicCQs)
{
  if (p1.x >= p2.x || p1.y >= p2.y)
  {
    throw std::logic_error("Impossible to build a rectangle");
  }
  createCQs(p1, p2, cmplxqds[0], cmplxqds[1], cmplxqds[2], cmplxqds[3]);
}

double abramov::Rectangle::getArea() const noexcept
{
  return cmplxqds[0].getArea() + cmplxqds[1].getArea() + cmplxqds[2].getArea() + cmplxqds[3].getArea();
}

abramov::rectangle_t abramov::Rectangle::getFrameRect() const noexcept
{
  ComplexQuad cmplxqd1 = cmplxqds[0];
  ComplexQuad cmplxqd4 = cmplxqds[3];
  const double width = cmplxqd4.getD().x - cmplxqd1.getA().x;
  double height = std::abs(cmplxqd4.getD().y - cmplxqd1.getA().y);
  if (height == 0)
  {
    height = cmplxqd1.getB().y - cmplxqd1.getA().y;
  }
  point_t pos;
  pos.x = (cmplxqd1.getA().x + cmplxqd4.getD().x) / 2;
  pos.y = (cmplxqd1.getA().y + cmplxqd4.getD().y) / 2;
  rectangle_t frame_rect{width, height, pos};
  return frame_rect;
}

void abramov::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; ++i)
  {
    cmplxqds[i].move(dx, dy);
  }
}

void abramov::Rectangle::move(point_t p)
{
  const point_t center = getFrameRect().pos;
  const double dx = p.x - center.x;
  const double dy = p.y - center.y;
  move(dx, dy);
}

void abramov::Rectangle::scale(double k)
{
  const double newWidth = (cmplxqds[3].getD().x - cmplxqds[0].getA().x) * k;
  double height = 0;
  const double dy = std::abs(cmplxqds[3].getD().y - cmplxqds[0].getA().y);
  if (dy == 0)
  {
    height = cmplxqds[0].getB().y - cmplxqds[0].getA().y;
  }
  else
  {
    height = dy;
  }
  const double newHeight = height * k;
  const point_t center = getFrameRect().pos;
  const double x2 = center.x + newWidth / 2;
  const double y2 = center.y + newHeight / 2;
  const double x1 = center.x - newWidth / 2;
  const double y1 = center.y - newHeight / 2;
  const point_t p1{x1, y1};
  const point_t p2{x2, y2};
  createCQs(p1, p2, cmplxqds[0], cmplxqds[1], cmplxqds[2], cmplxqds[3]);
}

abramov::Rectangle *abramov::Rectangle::clone() const
{
  return new Rectangle(*this);
}

