#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

mozhegova::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  pCent(p1),
  pVert(p2),
  pHori(p3)
{}

double mozhegova::Diamond::getArea() const
{
  double d1 = std::abs(pVert.y - pCent.y);
  double d2 = std::abs(pHori.x - pCent.x);
  return 2 * d1 * d2;
}

mozhegova::rectangle_t mozhegova::Diamond::getFrameRect() const
{
  double d1 = std::abs(pVert.y - pCent.y);
  double d2 = std::abs(pHori.x - pCent.x);
  return {2 * d2, 2 * d1, pCent};
}

void mozhegova::Diamond::move(point_t p)
{
  double d1 = pVert.y - pCent.y;
  double d2 = pHori.x - pCent.x;
  pCent = p;
  pVert = {pCent.x, pCent.y + d1};
  pHori = {pCent.x + d2, pCent.y};
}

void mozhegova::Diamond::move(double dx, double dy)
{
  pCent = {pCent.x + dx, pCent.y + dy};
  pVert = {pVert.x + dx, pVert.y + dy};
  pHori = {pHori.x + dx, pHori.y + dy};
}

void mozhegova::Diamond::scale(double k)
{
  double d1 = pVert.y - pCent.y;
  double d2 = pHori.x - pCent.x;
  pVert.y = pCent.y + d1 * k;
  pHori.x = pCent.x + d2 * k;
}
