#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <array>

namespace kushekbaev
{
  Diamond::Diamond(point_t middle,
    point_t diffX,
  point_t diffY):
  Parallelogram(
    {middle.x - diffX.x, middle.y},
    {middle.x + diffX.x, middle.y},
    {middle.x, middle.y - diffY.y}
  ),
  middle_(middle),
  diffX_(diffX),
  diffY_(diffY)
  {

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
    double dx = Z.x - middle.x;
    double dy = Z.y - middle.y;

    std::array<point_t*, 3> points = { &middle_, &diffX_, &diffY_, };

    for (point_t* point : points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Diamond::move(double dx, double dy)
  {
    std::array<point_t*, 3> points = { &middle_, &diffX_, &diffY_, };

    for (point_t* point : points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Diamond::scale(double V)
  {
    if (V <= 0)
    {
      throw std::out_of_range("Scale coefficient should be greater than zero\n");
    }
    diffY_.y = middle_.y + (diffY_.y - middle_.y) * V;
    diffX_.x = middle_.x + (diffX_.x - middle_.x) * V;
  }
}
