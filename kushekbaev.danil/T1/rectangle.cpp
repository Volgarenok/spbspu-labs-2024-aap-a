#include "rectangle.hpp"
#include <stdexcept>
#include <array>
#include "base-types.hpp"
#include "shapeUtils.hpp"

namespace kushekbaev
{
  Rectangle::Rectangle(point_t lowerLeft, point_t upperRight):
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

  void Rectangle::move(point_t scalePoint)
  {
    point_t middle = getFrameRect().pos;
    double dx = scalePoint.x - middle.x;
    double dy = scalePoint.y - middle.y;

    move(dx, dy);
  }

  void Rectangle::move(double dx, double dy)
  {
    std::array<point_t*, 2> points = { &lowerLeft_, &upperRight_, };
    movePoints(points, dx, dy);
  }

  void Rectangle::scale(double scaleCoeff)
  {
    if (scaleCoeff <= 0)
    {
      throw std::domain_error("Scale coefficient should be greater than zero\n");
    }
    point_t middle = getFrameRect().pos;

    std::array<point_t*, 2> points = { &lowerLeft_, &upperRight_, };
    scalePoints(points, scaleCoeff, middle);
  }
}
