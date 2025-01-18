#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <array>

namespace kushekbaev
{
  point_t parFirst { middle.x - diffX.x, middle.y - diffX.y };
  point_t parSecond { middle.x + diffX.x, middle.y + diffX.y };
  point_t parThird { middle.x, middle.y + diffY.y };
  Diamond::Diamond(const point_t middle, const point_t diffX, const point_t diffY):
    parallelogram_(parFirst, parSecond, parThird)
  {
    if (parFirst.x != parThird.x || parFirst.y != parSecond.y)
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
