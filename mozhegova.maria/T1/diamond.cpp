#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

mozhegova::Diamond::Diamond(point_t pCent, point_t pVert, point_t pHori):
  poly_(nullptr)
{
  point_t p = {0, 0};
  if (pCent.x == pHori.x && pCent.y == pVert.y)
  {
    p = pVert;
    pVert = pHori;
    pHori = p;
  }
  else if (pVert.x == pCent.x && pVert.y == pHori.y)
  {
    p = pVert;
    pVert = pCent;
    pCent = p;
  }
  else if (pVert.x == pHori.x && pVert.y == pCent.y)
  {
    p = pCent;
    pCent = pVert;
    pVert = pHori;
    pHori = p;
  }
  else if (pHori.x == pCent.x && pHori.y == pVert.y)
  {
    p = pCent;
    pCent = pHori;
    pHori = pVert;
    pVert = p;
  }
  else if (pHori.x == pVert.x && pHori.y == pCent.y)
  {
    p = pHori;
    pHori = pCent;
    pCent = p;
  }
  else if (!(pCent.x == pVert.x && pCent.y == pHori.y))
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  point_t coor[4] = {};
  double dx = std::abs(pCent.x - pHori.x);
  double dy = std::abs(pCent.y - pVert.y);
  coor[0] = {pCent.x, pCent.y - dy};
  coor[1] = {pCent.x + dx, pCent.y};
  coor[2] = {pCent.x, pCent.y + dy};
  coor[3] = {pCent.x - dx, pCent.y};
  poly_ = new Polygon(4, coor);
}

mozhegova::Diamond::~Diamond()
{
  delete poly_;
}

double mozhegova::Diamond::getArea() const
{
  return poly_->getArea();
}

mozhegova::rectangle_t mozhegova::Diamond::getFrameRect() const
{
  return poly_->getFrameRect();
}

void mozhegova::Diamond::move(point_t p)
{
  poly_->move(p);
}

void mozhegova::Diamond::move(double dx, double dy)
{
  poly_->move(dx, dy);
}

void mozhegova::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  poly_->scale(k);
}
