#include "rectangle.hpp"
#include <stdexcept>
#include <algorithm>
#include "shape.hpp"
#include "base-types.hpp"

abramov::Rectangle::Rectangle(const point_t &p1, const point_t &p2):
  cmplxqds(createCQs(p1, p2))
{
  if (p1.x >= p2.x || p1.y >= p2.y)
  {
    delete[] cmplxqds;
    throw std::logic_error("Impossible to build a rectangle");
  }
}

abramov::Rectangle::~Rectangle()
{
  delete[] cmplxqds;
}

double abramov::Rectangle::getArea() const noexcept
{
  double area = 0;
  constexpr size_t k = 4;
  for (size_t i = 0; i < k; ++i)
  {
    area += cmplxqds[i].getArea();
  }
  return area;
}

abramov::rectangle_t abramov::Rectangle::getFrameRect() const noexcept
{
  const rectangle_t rect1 = cmplxqds[0].getFrameRect();
  const double x1 = rect1.pos.x - rect1.width / 2;
  const double y1 = rect1.pos.y - rect1.height / 2;
  const rectangle_t rect2 = cmplxqds[3].getFrameRect();
  const double x2 = rect2.pos.x + rect2.width / 2;
  const double y2 = rect2.pos.y + rect2.height / 2;
  const double width = x2 - x1;
  double height = std::abs(y2 - y1);
  if (height == 0)
  {
    const double y3 = rect1.pos.y + rect1.height / 2;
    height = 2 * (y3 - y1);
  }
  const double px = (x1 + x2) / 2;
  const double py = (y1 + y2) / 2;
  point_t pos{ px, py };
  rectangle_t frame_rect{ width, height, pos };
  return frame_rect;
}

void abramov::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; ++i)
  {
    cmplxqds[i].move(dx, dy);
  }
}

void abramov::Rectangle::move(const point_t &p)
{
  const point_t center = getFrameRect().pos;
  const double dx = p.x - center.x;
  const double dy = p.y - center.y;
  move(dx, dy);
}

void abramov::Rectangle::scale(double k)
{
  const rectangle_t rect1 = cmplxqds[0].getFrameRect();
  const double x1 = rect1.pos.x - rect1.width / 2;
  const double y1 = rect1.pos.y - rect1.height / 2;
  const rectangle_t rect2 = cmplxqds[3].getFrameRect();
  const double x2 = rect2.pos.x + rect2.width / 2;
  const double y2 = rect2.pos.y + rect2.height / 2;
  const double newWidth = (x2 - x1) * k;
  double height = 0;
  const double dy = std::abs(y2 - y1);
  if (dy == 0)
  {
    height = 2 * rect1.height;
  }
  else
  {
    height = dy;
  }
  const double newHeight = height * k;
  const point_t center = getFrameRect().pos;
  const double xp2 = center.x + newWidth / 2;
  const double yp2 = center.y + newHeight / 2;
  const double xp1 = center.x - newWidth / 2;
  const double yp1 = center.y - newHeight / 2;
  const point_t p1{ xp1, yp1 };
  const point_t p2{ xp2, yp2 };
  ComplexQuad *oldcqs = cmplxqds;
  cmplxqds = createCQs(p1, p2);
  delete[] oldcqs;
}

abramov::Rectangle *abramov::Rectangle::clone() const
{
  return new Rectangle(*this);
}

