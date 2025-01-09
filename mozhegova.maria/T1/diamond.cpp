#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

mozhegova::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  pCent_(p1),
  pVert_(p2),
  pHori_(p3)
{
  point_t p = {0, 0};
  if (pCent_.x == pHori_.x && pCent_.y == pVert_.y)
  {
    p = pVert_;
    pVert_ = pHori_;
    pHori_ = p;
  }
  else if (pVert_.x == pCent_.x && pVert_.y == pHori_.y)
  {
    p = pVert_;
    pVert_ = pCent_;
    pCent_ = p;
  }
  else if (pVert_.x == pHori_.x && pVert_.y == pCent_.y)
  {
    p = pCent_;
    pCent_ = pVert_;
    pVert_ = pHori_;
    pHori_ = p;
  }
  else if (pHori_.x == pCent_.x && pHori_.y == pVert_.y)
  {
    p = pCent_;
    pCent_ = pHori_;
    pHori_ = pVert_;
    pVert_ = p;
  }
  else if (pHori_.x == pVert_.x && pHori_.y == pCent_.y)
  {
    p = pHori_;
    pHori_ = pCent_;
    pCent_ = p;
  }
  else if (!(pCent_.x == pVert_.x && pCent_.y == pHori_.y))
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}

double mozhegova::Diamond::getArea() const
{
  double d1 = std::abs(pVert_.y - pCent_.y);
  double d2 = std::abs(pHori_.x - pCent_.x);
  return 2 * d1 * d2;
}

mozhegova::rectangle_t mozhegova::Diamond::getFrameRect() const
{
  double d1 = std::abs(pVert_.y - pCent_.y);
  double d2 = std::abs(pHori_.x - pCent_.x);
  return {2 * d2, 2 * d1, pCent_};
}

void mozhegova::Diamond::move(point_t p)
{
  double d1 = pVert_.y - pCent_.y;
  double d2 = pHori_.x - pCent_.x;
  pCent_ = p;
  pVert_ = {pCent_.x, pCent_.y + d1};
  pHori_ = {pCent_.x + d2, pCent_.y};
}

void mozhegova::Diamond::move(double dx, double dy)
{
  pCent_ = {pCent_.x + dx, pCent_.y + dy};
  pVert_ = {pVert_.x + dx, pVert_.y + dy};
  pHori_ = {pHori_.x + dx, pHori_.y + dy};
}

void mozhegova::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  double d1 = pVert_.y - pCent_.y;
  double d2 = pHori_.x - pCent_.x;
  pVert_.y = pCent_.y + d1 * k;
  pHori_.x = pCent_.x + d2 * k;
}
