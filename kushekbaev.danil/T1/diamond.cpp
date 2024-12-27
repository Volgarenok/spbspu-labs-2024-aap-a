#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include "shape.hpp"

namespace kushekbaev
{
  Diamond::Diamond(point_t middle,
    point_t diffX,
    point_t diffY):
    middle_(middle),
    diffX_(diffX),
    diffY_(diffY)
  {
    if (!isTriangle(middle_, diffX_, diffY_))
    {
      throw std::invalid_argument("First three points wouldnt make a triangle\n");
    }
  }

  double Diamond::getArea() const
  {
    return std::fabs((middle_.x - diffX_.x) * (middle_.y - diffY_.y) * 2);
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return { std::fabs((middle_.x - diffX_.x)) * 2, std::fabs((middle_.y - diffY_.y) * 2), middle_ };
  }

  void Diamond::move(point_t Z)
  {
    point_t middle = getFrameRect().pos;
    double moveX = Z.x - middle.x;
    double moveY = Z.y - middle.y;
    middle_ = Z;
    moveDelta(moveX, moveY, diffX_);
    moveDelta(moveX, moveY, diffY_);
  }

  void Diamond::move(double dx, double dy)
  {
    moveDelta(dx, dy, middle_);
    moveDelta(dx, dy, diffX_);
    moveDelta(dx, dy, diffY_);
  }

  void Diamond::scale(double V)
  {
    if (V <= 0)
    {
      throw std::invalid_argument("Scale coefficient should be greater than zero\n");
    }
    isoScaling(V, middle_, diffX_);
    isoScaling(V, middle_, diffY_);
  }
}
