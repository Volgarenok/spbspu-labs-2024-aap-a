#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

hismatova::rectangle::rectangle(const point_t& bottomLeft, const point_t& topRight):
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{}
double hismatova::rectangle::getArea() const
{
  double width = std::abs(topRight_.x - bottomLeft_.x);
  double height = std::abs(topRight_.y - bottomLeft_.y);
  return width * height;
}
hismatova::rectangle_t hismatova::rectangle::getFrameRect() const
{
  double width = std::abs(topRight_.x - bottomLeft_.x);
  double height = std::abs(topRight_.y - bottomLeft_.y);
  hismatova::point_t center = { (bottomLeft_.x + topRight_.x) / 2, (bottomLeft_.y + topRight_.y) / 2 };
  return {width, height, center};
}
void hismatova::rectangle::move(const point_t &newPos)
{
  double dx = newPos.x - getFrameRect().pos.x;
  double dy = newPos.y - getFrameRect().pos.y;
  move(dx, dy);
}
void hismatova::rectangle::move(double dx, double dy)
{
  bottomLeft_.x += dx;
  bottomLeft_.y += dy;
  topRight_.x += dx;
  topRight_.y += dy;
}
void hismatova::rectangle::scale(double index)
{
  if (index <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive.");
  }
  hismatova::point_t center = getFrameRect().pos;
  bottomLeft_.x = center.x + (bottomLeft_.x - center.x) * index;
  bottomLeft_.y = center.y + (bottomLeft_.y - center.y) * index;
  topRight_.x = center.x + (topRight_.x - center.x) * index;
  topRight_.y = center.y + (topRight_.y - center.y) * index;
}
