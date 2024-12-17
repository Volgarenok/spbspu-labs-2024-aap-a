#include "rectangle.hpp"
#include "base-types.hpp"
#include <cmath>

shramko::Rectangle::Rectangle(point_t leftBottom, point_t rightTop): leftBottom({0.0, 0.0}), rightTop({0.0, 0.0})
{
  leftBottom_.x = leftBottom.x;
  leftBottom_.y = leftBottom.y;
  rightTop_.x = rightTop.x;
  rightTop_.y = rightTop.y;
}

double shramko:Rectangle:getArea() const
{
  double lenWidth = rightTop.x - leftBottom_.x;
  double lenHeight = rightTop.y - leftBottom_.y;

  return lenWidth * lenHeight;
}

shramko::rectangle_t shramko::Rectangle::getRectangleFrame() const
{
  rectangle_t rectangleFrame;

  rectangleFrame.pos.x = leftBottom_.x + (width / 2.0);
  rectangleFrame.pos.y = leftBottom_.y + (height / 2.0);
  rectangleFrame.height = rightTop_.y - leftBottom_.y;
  rectangleFrame.width = rightTop_.x - leftBottom_.x;

  return rectangleFrame;
}

void shramko::Rectangle::move(point_t s)
{
  leftBottom_.x += x;
  leftBottom_.y += y;
  rightTop_.x += x;
  rightTop_.y += y;
}

void shramko::Rectangle::move(double x, double y)
{
  point_t pos = getRectangleFrame().pos;
  double xMove = centre.x - pos.x;
  double yMove = centre.y - pos.y;
  move(xMove, yMove);
}

void shramko::Rectangle::scale(double k)
{
  rectangle_t rectangleFrame = getRectangleFrame();
  point_t pos = rectangleFrame().pos;

  leftBottom_.x = pos.x + (leftBottom_.x - pos.x) * k;
  leftBottom_.y = pos.y + (leftBottom_.y - pos.y) * k;
  rightTop_.x = pos.x + (rightTop_.x - pos.x) * k;
  rightTop_.y = pos.y + (rightTop_.y - pos.y) * k;
}
