#include "rectangle.hpp"
#include <stdexcept>
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
    point_t mid = getFrameRect().pos;
    double dx = scalePoint.x - mid.x;
    double dy = scalePoint.y - mid.y;

    move(dx, dy);
  }

  void Rectangle::move(double dx, double dy)
  {
    size_t size = 2;
    point_t* points[] = { &lowerLeft_, &upperRight_ };
    movePoints(points, size, dx, dy);
  }

  void Rectangle::scale(double scaleCoeff)
  {
    if (scaleCoeff <= 0)
    {
      throw std::logic_error("Scale coefficient should be greater than zero\n");
    }
    point_t mid = getFrameRect().pos;

    size_t size = 2;
    point_t* points[] = { &lowerLeft_, &upperRight_ };
    scalePoints(points, size, scaleCoeff, mid);
  }

  Shape* Rectangle::clone() const
  {
    return new Rectangle(*this);
  }
}
