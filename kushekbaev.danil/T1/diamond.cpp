#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

kushekbaev::Diamond::Diamond(const point_t mid, const point_t modX, const point_t modY):
  parallelogram_({ mid.x - modX.x, mid.y - modX.y }, { mid.x + modX.x, mid.y + modX.y }, { mid.x, mid.y + modY.y })
{
  if ((mid.x - modX.x != mid.x) || (mid.y - modX.y != mid.y + modY.y))
  {
    throw std::invalid_argument("Incorrect diamond\n");
  }
}

double kushekbaev::Diamond::getArea() const
{
  return parallelogram_.getArea();
}

kushekbaev::rectangle_t kushekbaev::Diamond::getFrameRect() const
{
  return parallelogram_.getFrameRect();
}

void kushekbaev::Diamond::move(point_t scalePoint)
{
  return parallelogram_.move(scalePoint);
}

void kushekbaev::Diamond::move(double dx, double dy)
{
  return parallelogram_.move(dx, dy);
}

void kushekbaev::Diamond::scale(double scaleCoeff)
{
  return parallelogram_.scale(scaleCoeff);
}

kushekbaev::Shape* kushekbaev::Diamond::clone() const noexcept
{
  return new Diamond(*this);
}
