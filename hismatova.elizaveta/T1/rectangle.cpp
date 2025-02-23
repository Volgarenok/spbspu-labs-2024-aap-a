#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

hismatova::Rectangle::Rectangle(const point_t& bottomLeft, const point_t& topRight):
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{
  if ((topRight_.y - bottomLeft_.y) * (topRight_.x - bottomLeft_.x) <= 0 || topRight_.y <= bottomLeft_.y || topRight_.x <= bottomLeft_.x)
  {
    throw std::invalid_argument("rectangle cannot be built");
  }
}
double hismatova::Rectangle::getArea() const
{
  double width = topRight_.x - bottomLeft_.x;
  double height = topRight_.y - bottomLeft_.y;
  return width * height;
}
hismatova::rectangle_t hismatova::Rectangle::getFrameRect() const
{
  double width = topRight_.x - bottomLeft_.x;
  double height = topRight_.y - bottomLeft_.y;
  point_t pos = { bottomLeft_.x + width / 2.0, bottomLeft_.y + height / 2.0 };
  return {height, width, pos};
}
void hismatova::Rectangle::move(const point_t &newPos)
{
  double dx = newPos.x - this->getFrameRect().pos.x;
  double dy = newPos.y - this->getFrameRect().pos.y;
  move(dx, dy);
}
void hismatova::Rectangle::move(double dx, double dy)
{
  bottomLeft_.x += dx;
  bottomLeft_.y += dy;
  topRight_.x += dx;
  topRight_.y += dy;
}
void hismatova::Rectangle::scale(double index)
{
  point_t center = this->getFrameRect().pos;
  bottomLeft_.x = center.x + (bottomLeft_.x - center.x) * index;
  bottomLeft_.y = center.y + (bottomLeft_.y - center.y) * index;
  topRight_.x = center.x + (topRight_.x - center.x) * index;
  topRight_.y = center.y + (topRight_.y - center.y) * index;
}
