#include "rectangle.hpp"

namespace kushekbaev
{
  Rectangle::Rectangle(point_t lowerLeft, point_t upperRight) : lowerLeft_(lowerLeft), upperRight_(upperRight)
  {
  }

  double Rectangle::getArea() const
  {
    double area = ((upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y));
    return area;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double width = upperRight_.x - lowerLeft_.x;
    double length = upperRight_.y - lowerLeft_.y;
    rectangle_t frame;
    frame.pos.x = lowerLeft_.x;
    frame.pos.y = upperRight_.y;
    frame.width = width;
    frame.length = length;
    return frame;
  }

  void Rectangle::move(point_t Z)
  {
    point_t middle;
    middle.x = (upperRight_.x - lowerLeft_.x) / 2;
    middle.y =  (upperRight_.y - lowerLeft_.y) / 2;
    point_t move;
    move.x = Z.x - middle.x;
    move.y = Z.x - middle.y;
    lowerLeft_.x += move.x;
    upperRight_.x += move.y;
    lowerLeft_.y += move.x;
    upperRight_.y += move.y;
  }

  void Rectangle::move(double dy, double dx)
  {
    lowerLeft_.x += dx;
    upperRight_.x += dx;
    lowerLeft_.y += dy;
    upperRight_.y += dy;
  }

  void Rectangle::scale(double V)
  {
    point_t middle = getFrameRect().pos;
    lowerLeft_.x = (lowerLeft_.x - middle.x) * V + middle.x;
    upperRight_.x = (upperRight_.x - middle.x) * V + middle.x;
    lowerLeft_.y = (lowerLeft_.y - middle.y) * V + middle.y;
    upperRight_.y = (upperRight_.y - middle.y) * V + middle.y;
  }
}
