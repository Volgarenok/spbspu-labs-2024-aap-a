#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

namespace kushekbaev
{
  Diamond::Diamond(const point_t mid, const point_t modX, const point_t modY):
    parallelogram_({ mid.x - modX.x, mid.y - modX.y }, { mid.x + modX.x, mid.y + modX.y }, { mid.x, mid.y + modY.y })
  {
    if ((mid.x - modX.x != mid.x) || (mid.y - modX.y != mid.y + modY.y))
    {
      throw std::invalid_argument("Incorrect diamond\n");
    }
  }

  double Diamond::getArea() const
  {
    return parallelogram_.getArea();
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return parallelogram_.getFrameRect();
  }

  void Diamond::move(point_t scalePoint)
  {
    return parallelogram_.move(scalePoint);
  }

  void Diamond::move(double dx, double dy)
  {
    return parallelogram_.move(dx, dy);
  }

  void Diamond::scale(double scaleCoeff)
  {
    return parallelogram_.scale(scaleCoeff);
  }

  Shape* Diamond::clone() const noexcept
  {
    return new Diamond(*this);
  }
}
