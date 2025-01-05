#include "rectangle.hpp"
#include <stdexcept>
#include <array>
#include "base-types.hpp"

namespace kushekbaev
{
  Rectangle::Rectangle(point_t lowerLeft,
    point_t upperRight):
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
  {
    if (lowerLeft.x >= upperRight.x || lowerLeft.y >= upperRight.x)
    {
      throw std::invalid_argument("Incorrect rectangle\n");
    }
  }

  double Rectangle::getArea() const
  {
    return (upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double middleForX = lowerLeft_.x + (upperRight_.x - lowerLeft_.x) / 2;
    double middleForY = lowerLeft_.y + (upperRight_.y - lowerLeft_.y) / 2;
    return { upperRight_.x - lowerLeft_.x, upperRight_.y - lowerLeft_.y, { middleForX, middleForY } };
  }

  void Rectangle::move(point_t Z)
  {
    point_t middle = getFrameRect().pos;
    double dx = Z.x - middle.x;
    double dy = Z.y - middle.y;

    std::array<point_t*, 2> points = { &lowerLeft_, &upperRight_, };

    for (point_t* point : points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Rectangle::move(double dx, double dy)
  {
    std::array<point_t*, 2> points = { &lowerLeft_, &upperRight_, };

    for (point_t* point : points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Rectangle::scale(double V)
  {
    if (V <= 0)
    {
      throw std::out_of_range("Scale coefficient should be greater than zero\n");
    }
    point_t middle = getFrameRect().pos;

    std::array<point_t*, 2> points = { &lowerLeft_, &upperRight_, };

    for (point_t* point : points)
    {
      point->x = middle.x + (point->x - middle.x) * V;
      point->y = middle.y + (point->y - middle.y) * V;
    }
  }
}
