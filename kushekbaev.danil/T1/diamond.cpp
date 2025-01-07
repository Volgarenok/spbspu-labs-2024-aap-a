#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <array>

namespace kushekbaev
{
  Diamond::Diamond(point_t middle, point_t diffX, point_t diffY):
    parallelogram_(
      { middle.x - diffX.x, middle.y - diffX.y },
      { middle.x + diffX.x, middle.y + diffX.y },
      { middle.x + diffY.x, middle.y + diffY.y }
    )
  {

  }

  double Diamond::getArea() const
  {
    return parallelogram_.getArea();
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return parallelogram_.getFrameRect();
  }

  void Diamond::move(point_t Z)
  {
    return parallelogram_.move(Z);
  }

  void Diamond::move(double dx, double dy)
  {
    return parallelogram_.move(dx, dy);
  }

  void Diamond::scale(double V)
  {
    return parallelogram_.scale(V);
  }
}
