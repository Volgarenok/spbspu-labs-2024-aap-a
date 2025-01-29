#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "complexquad.hpp"
#include "shape.hpp"
namespace
{
  kiselev::Complexquad createComp(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3, size_t id)
  {
    kiselev::point_t center = { 0, 0 };
    kiselev::point_t pHorizontal = { 0, 0 };
    kiselev::point_t pVertical = { 0, 0 };
    if (p1.x == p2.x && p1.y == p3.y)
    {
      center = { p1.x, p1.y };
      pHorizontal = { p2.x, p2.y };
      pVertical = { p3.x, p3.y };
    }
    else if (p1.x == p3.x && p1.y == p2.y)
    {
      center = { p1.x, p1.y };
      pHorizontal = { p3.x, p3.y };
      pVertical = { p2.x, p2.y };
    }
    else if (p2.x == p1.x && p2.y == p3.y)
    {
      center = { p2.x, p2.y };
      pHorizontal = { p3.x, p3.y };
      pVertical = { p1.x, p1.y };
    }
    else if (p2.x == p3.x && p2.y == p1.y)
    {
      center = { p2.x, p2.y };
      pHorizontal = { p1.x, p1.y };
      pVertical = { p3.x, p3.y };
    }
    else if (p3.x == p1.x && p3.y == p2.y)
    {
      center = { p3.x, p3.y };
      pHorizontal = { p1.x, p1.y };
      pVertical = { p2.x, p2.y };
    }
    else if (p3.x == p2.x && p3.y == p1.y)
    {
      center = { p3.x, p3.y };
      pHorizontal = { p2.x, p2.y };
      pVertical = { p1.x, p1.y };
    }
    else
    {
      throw std::invalid_argument("Invalid coordinates");
    }
    kiselev::point_t pHorizontal2 = { center.x + (center.x - pHorizontal.x), pHorizontal.y};
    kiselev::point_t pVertical2 = {pVertical.x, center.y + (center.y - pVertical.y)};
    if (id == 1)
    {
      return { pHorizontal2, pHorizontal, pVertical, pVertical2 };
    }
    else
    {
      return { pHorizontal2, pHorizontal, pVertical2, pVertical };
    }
  }
}
kiselev::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  comp1(createComp(p1, p2, p3, 1)),
  comp2(createComp(p1, p2, p3, 2))
{
}
double kiselev::Diamond::getArea() const
{
  return comp1.getArea() + comp2.getArea();
}
kiselev::rectangle_t kiselev::Diamond::getFrameRect() const
{
  return comp1.getFrameRect();
}
void kiselev::Diamond::move(double dx, double dy)
{
  comp1.move(dx, dy);
  comp2.move(dx, dy);
}
void kiselev::Diamond::move(kiselev::point_t a)
{
  point_t center = comp1.getFrameRect().pos;
  double dx = a.x - center.x;
  double dy = a.y - center.y;
  move(dx, dy);
}
void kiselev::Diamond::scale(double k)
{
  comp1.scale(k);
  comp2.scale(k);
}
kiselev::Shape* kiselev::Diamond::clone() const
{
  return new Diamond(*this);
}
