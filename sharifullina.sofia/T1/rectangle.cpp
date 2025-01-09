#include "rectangle.hpp"

sharifullina::Rectangle::Rectangle(point_t lowLeft, point_t uppRight):
  lowLeft_(lowLeft),
  uppRight_(uppRight)
{}

double sharifullina::Rectangle::getArea() const
{
  double width = uppRight_.x - lowLeft_.x;
  double height = uppRight_.y - lowLeft_.y;
  return width * height;
}

sharifullina::rectangle_t sharifullina::Rectangle::getFrameRect() const
{
  double width = uppRight_.x - lowLeft_.x;
  double height = uppRight_.y - lowLeft_.y;
  double x_ = lowLeft_.x + (width / 2.0);
  double y_ = lowLeft_.y + (height / 2.0);
  return {width, height, {x_, y_}};
}

void sharifullina::Rectangle::move(point_t p)
{
  point_t center = getFrameRect().pos;
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  lowLeft_ = {lowLeft_.x + dx, lowLeft_.y + dy};
  uppRight_ = {uppRight_.x + dx, uppRight_.y + dy};
}

void sharifullina::Rectangle::move(double dx, double dy)
{
  lowLeft_ = {lowLeft_.x + dx, lowLeft_.y + dy};
  uppRight_ = {uppRight_.x + dx, uppRight_.y + dy};
}

void sharifullina::Rectangle::scale(double k)
{
  point_t center = getFrameRect().pos;
  double xLeft = center.x - (center.x - lowLeft_.x) * k;
  double yLeft = center.y - (center.y - lowLeft_.y) * k;
  lowLeft_ = {xLeft, yLeft};
  double xRight = center.x + (uppRight_.x - center.x) * k;
  double yRight = center.y + (uppRight_.y - center.y) * k;
  uppRight_ = {xRight, yRight};
}
