#include "diamond.hpp"
#include <cmath>
#include <new>
#include <stdexcept>
#include "base-types.hpp"
#include "cmath"
#include "complexquad.hpp"
kiselev::Diamond::Diamond(kiselev::point_t pVertical, point_t pHorizontal) :
  comp1(nullptr),
  comp2(nullptr)
{
  point_t pHorizontal2 = {pHorizontal.x * -1, pHorizontal.y};
  point_t pVertical2 = {pVertical.x, pVertical.y * -1};
  try
  {
    comp1 = new Complexquad(pHorizontal2, pHorizontal, pVertical, pVertical2);
    comp2 = new Complexquad(pHorizontal2, pHorizontal, pVertical2, pVertical);
  }
  catch (const std::bad_alloc &e)
  {
    delete comp1;
    throw;
  }
  catch (const std::invalid_argument &e)
  {
    delete comp1;
    delete comp2;
    throw;
  }
}
double kiselev::Diamond::getArea() const noexcept
{
  return comp1->getArea() + comp2->getArea();
}
kiselev::rectangle_t kiselev::Diamond::getFrameRect() const noexcept
{
  return comp1->getFrameRect();
}
void kiselev::Diamond::move(double dx, double dy) noexcept
{
  comp1->move(dx, dy);
  comp2->move(dx, dy);
}
void kiselev::Diamond::move(kiselev::point_t a) noexcept
{
  comp1->move(a);
  comp2->move(a);
}
void kiselev::Diamond::scale(double k) noexcept
{
  comp1->scale(k);
  comp2->scale(k);
}
kiselev::Diamond::~Diamond()
{
  delete comp1;
  delete comp2;
}
