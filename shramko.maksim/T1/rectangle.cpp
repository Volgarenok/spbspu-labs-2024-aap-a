#include "rectangle.hpp"
#include <stdexcept>
#include <stdlib.h>
#include <cmath>

shramko::Rectangle::Rectangle(point_t leftBottom, point_t rightTop):
  leftBottom_(leftBottom),
  rightTop_(rightTop)
{
  if (leftBottom.x <= rightTop.x && leftBottom.y <= rightTop.y)
  {
    leftBottom_.x = leftBottom.x;
    leftBottom_.y = leftBottom.y;
    rightTop_.x = rightTop.x;
    rightTop_.y = rightTop.y;
  }
  else
  {
    throw std::invalid_argument("Rect size err\n");
  }
}

double shramko::Rectangle::getArea() const
{
  double weight = rightTop_.x - leftBottom_.x;
  double height = rightTop_.y - leftBottom_.y;

  return weight * height;
}

shramko::rectangle_t shramko::Rectangle::getFrameRect() const
{
  rectangle_t rectFrame;

  rectFrame.height = rightTop_.y - leftBottom_.y;
  rectFrame.width = rightTop_.x - leftBottom_.x;
  rectFrame.pos.x = leftBottom_.x + (rectFrame.width / 2.0L);
  rectFrame.pos.y = leftBottom_.y + (rectFrame.height / 2.0L);

  return rectFrame;
}

void shramko::Rectangle::move(point_t point)
{
  point_t pos = getFrameRect().pos;
  double xMove = point.x - pos.x;
  double yMove = point.y - pos.y;
  move(xMove, yMove);
}

void shramko::Rectangle::move(double x, double y)
{
  leftBottom_.x += x;
  leftBottom_.y += y;
  rightTop_.x += x;
  rightTop_.y += y;
}

void shramko::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Rect scale err\n");
  }
  rectangle_t rectFrame = getFrameRect();
  point_t pos = rectFrame.pos;

  leftBottom_.x = pos.x + (leftBottom_.x - pos.x) * k;
  leftBottom_.y = pos.y + (leftBottom_.y - pos.y) * k;
  rightTop_.x = pos.x + (rightTop_.x - pos.x) * k;
  rightTop_.y = pos.y + (rightTop_.y - pos.y) * k;
}
