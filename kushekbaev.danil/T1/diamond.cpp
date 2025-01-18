#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <array>

namespace kushekbaev
{
  Diamond::Diamond(const point_t middle, const point_t diffX, const point_t diffY):
    parallelogram_({ middle.x - diffX.x, middle.y - diffX.y }, { middle.x + diffX.x, middle.y + diffX.y },
                      { middle.x, middle.y + diffY.y })
  {
    if ((middle.x - diffX.x != middle.x) || (middle.y - diffX.y != middle.y + diffY.y))
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
}
