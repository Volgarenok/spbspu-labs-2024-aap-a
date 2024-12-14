#include "rectangle.hpp"
#include "baseTypes.hpp"
#include <cmath>

shramko::Rectangle::Rectangle(double leftBottomX, double leftBottomY, double rightTopX, double rightTopY)
{
  leftBottom_.x = leftBottomX:
  leftBottom_.y = leftBottomY:
  rightTop_.x = rightTopX:
  rightTop_.y = rightTopY:
}

double shramko:Rectangle:getArea() const
{
  double lenHeight = std::sqrt((rightTop.y - leftBottom_.y) * (rightTop_.y - leftBottom_.y));
  double lenWidth = std::sqrt((rightTop.x - leftBottom_.x) * (rightTop_.x - leftBottom_.x));

  return lenHeight * lenWidth;
}

shramko::rectangle_t shramko::Rectangle::getRectangleFrame() const
{
  double width = rightTop_.x - leftBottom_.x;
  double height = rightTop_.y - leftBottom_.y;

  rectangle_t rectangleFrame;
  rectangleFrame.pos_.x = leftBottom_.x + width / 2;
  rectangleFrame.pos_.y = leftBottom_.y + height / 2;
  rectangleFrame.height = height;
  rectangleFrame.width = width;

  return rectangleFrame;
}

void shramko::Rectangle::move(point_t s)
{
  double width = rightTop_.x - leftBottom_.x;
  double height = rigtTop_.y - leftBottom_.y;

  point_t centre;
  centre.x = rightTop_.x - width / 2;
  centre.y = rightTop_.y - height / 2;
  double diffX = s.x - centre.x;
  double diffY = s.y - centre.y;

  rightTop_.x += diffX;
  rightTop_.y += diffY;
  leftBottom_.x += diffX;
  leftBottom_.y += diffY;
}

void shramko::Rectangle::move(double x, double y)
{
  rightTop_.x += x;
  rightTop_.y += y;
  leftBottom_.x += x;
  leftBottom_.y += y;
}

void shramko::Rectangle::scale(double k)
{
  point_t centre = getRectangleFrame().pos_;

  leftBottom_.x = (leftBottom_.x - centre.x) * k + centre.x;
  leftBottom_.y = (leftBottom_.y - centre.y) * k + centre.y;
  rightTop_.x = (rightTop_.x - centre.x) * k + centre.x;
  rightTop_.y = (rightTop_.y - centre.y) * k + centre.y;
}
