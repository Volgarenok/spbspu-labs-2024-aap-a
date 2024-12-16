#include "diamond.hpp"
#include "shape.hpp"
#include <cmath>
#include <stdexcept>

namespace kushekbaev
{
  Diamond::Diamond(point_t middle, point_t diffX, point_t diffY)
  : middle_(middle), diffX_(diffX), diffY_(diffY){}

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
    point_t middle = this->getFrameRect().pos;
    double moveX = Z.x - middle.x;
    double moveY = Z.y - middle.y;
    middle_ = Z;
    diffX_.x += moveX;
    diffX_.y += moveY;
    diffY_.x += moveX;
    diffY_.y += moveY;
  }

  void Diamond::move(double dx, double dy)
  {
    middle_.x += dx;
    middle_.y += dy;
    diffX_.x += dx;
    diffX_.y += dy;
    diffY_.x += dx;
    diffY_.y += dy;
  }

  void Diamond::scale(double V)
  {
    if (V <= 0)
    {
      throw std::invalid_argument("Scale coefficient should be greater than zero\n");
    }
    point_t middle = this->getFrameRect().pos;
    diffY_.y = middle_.y + (diffY_.y - middle_.y) * V;
    diffX_.x = middle_.x + (diffX_.x - middle_.x) * V;
  }

}
