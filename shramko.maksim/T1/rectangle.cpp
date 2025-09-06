#include "rectangle.hpp"
#include <stdexcept>

namespace shramko
{
  Rectangle::Rectangle(point_t leftBottom, point_t rightTop):
    leftBottom_(leftBottom),
    rightTop_(rightTop)
  {
    if (leftBottom.x < rightTop.x && leftBottom.y < rightTop.y)
    {
      leftBottom_.x = leftBottom.x;
      leftBottom_.y = leftBottom.y;
      rightTop_.x = rightTop.x;
      rightTop_.y = rightTop.y;
      center_.x = leftBottom_.x + (rightTop_.x - leftBottom_.x)/2;
      center_.y = leftBottom.y + (rightTop_.y - leftBottom_.y)/2;
    }
    else
    {
      throw std::invalid_argument("Rect size err\n");
    }
  }

  double Rectangle::getArea() const
  {
    double width = rightTop_.x - leftBottom_.x;
    double height = rightTop_.y - leftBottom_.y;
    return width * height;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double height = rightTop_.y - leftBottom_.y;
    double width = rightTop_.x - leftBottom_.x;
    double x_ = leftBottom_.x + (width / 2.0);
    double y_ = leftBottom_.y + (height / 2.0);
    return {width, height, {x_, y_}};
  }

  void Rectangle::move(double x, double y)
  {
    point_t points[2] = {leftBottom_, rightTop_};
    movePoints(points, 2, x, y);
    leftBottom_ = points[0];
    rightTop_ = points[1];
  }

  void Rectangle::doScale(double k)
  {
    point_t points[2] = {leftBottom_, rightTop_};
    scalePoints(points, 2, k, center_);
    leftBottom_ = points[0];
    rightTop_ = points[1];
  }
}
