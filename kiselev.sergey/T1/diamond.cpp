#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
namespace
{
  void createArrPoint(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3, kiselev::point_t* arr)
  {
    kiselev::point_t center = { 0, 0 };
    arr[0] = { 0, 0 };
    arr[1] = { 0, 0 };
    if (p1.x == p2.x && p1.y == p3.y)
    {
      center = { p1.x, p1.y };
      arr[0] = { p2.x, p2.y };
      arr[1] = { p3.x, p3.y };
    }
    else if (p1.x == p3.x && p1.y == p2.y)
    {
      center = { p1.x, p1.y };
      arr[0] = { p3.x, p3.y };
      arr[1] = { p2.x, p2.y };
    }
    else if (p2.x == p1.x && p2.y == p3.y)
    {
      center = { p2.x, p2.y };
      arr[0] = { p3.x, p3.y };
      arr[1] = { p1.x, p1.y };
    }
    else if (p2.x == p3.x && p2.y == p1.y)
    {
      center = { p2.x, p2.y };
      arr[0] = { p1.x, p1.y };
      arr[1] = { p3.x, p3.y };
    }
    else if (p3.x == p1.x && p3.y == p2.y)
    {
      center = { p3.x, p3.y };
      arr[0] = { p1.x, p1.y };
      arr[1] = { p2.x, p2.y };
    }
    else if (p3.x == p2.x && p3.y == p1.y)
    {
      center = { p3.x, p3.y };
      arr[0] = { p2.x, p2.y };
      arr[1] = { p1.x, p1.y };
    }
    else
    {
      throw std::invalid_argument("Invalid coordinates");
    }
    arr[2] = { center.x + (center.x - arr[0].x), arr[0].y };
    arr[3] = { arr[1].x, center.y + (center.y - arr[1].y) };
  }
  kiselev::Complexquad createComplexquad(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3, bool isFirst)
  {
    constexpr size_t size = 4;
    kiselev::point_t arr[size] = {};
    createArrPoint(p1, p2, p3, arr);
    return isFirst ? kiselev::Complexquad(arr[2], arr[0], arr[1], arr[3]) : kiselev::Complexquad(arr[2], arr[0], arr[3], arr[1]);
  }
  kiselev::Complexquad createFirstComp(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3)
  {
    return createComplexquad(p1, p2, p3, true);
  }
  kiselev::Complexquad createSecondComp(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3)
  {
    return createComplexquad(p1, p2, p3, false);
  }
}
kiselev::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  comp1_(createFirstComp(p1, p2, p3)),
  comp2_(createSecondComp(p1, p2, p3))
{}
double kiselev::Diamond::getArea() const
{
  return comp1_.getArea() + comp2_.getArea();
}
kiselev::rectangle_t kiselev::Diamond::getFrameRect() const
{
  return comp1_.getFrameRect();
}
void kiselev::Diamond::move(double dx, double dy)
{
  comp1_.move(dx, dy);
  comp2_.move(dx, dy);
}
void kiselev::Diamond::move(point_t a)
{
  const point_t center = comp1_.getFrameRect().pos;
  const double dx = a.x - center.x;
  const double dy = a.y - center.y;
  move(dx, dy);
}
void kiselev::Diamond::scale(double k)
{
  comp1_.scale(k);
  comp2_.scale(k);
}
kiselev::Shape* kiselev::Diamond::clone() const
{
  return new Diamond(*this);
}
