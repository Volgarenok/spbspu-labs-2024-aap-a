#include "rectangle.hpp"
#include <iostream>

gavrilova::Rectangle::Rectangle(const point_t& pBottomLeft, const point_t& pTopRight):
  pBottomLeft_({0,0}),
  pTopRight_({0,0})
{
  if (pBottomLeft.x < pTopRight.x && pBottomLeft.y < pTopRight.y) {
    pBottomLeft_.x = pBottomLeft.x;
    pBottomLeft_.y = pBottomLeft.y;
    pTopRight_.x = pTopRight.x;
    pTopRight_.y = pTopRight.y;
  } else {
    throw std::logic_error("Invalid arguments for rectangle");
  }
}
gavrilova::Rectangle::Rectangle(const Rectangle& other):
  pBottomLeft_(other.pBottomLeft_),
  pTopRight_(other.pTopRight_)
{}

double gavrilova::Rectangle::getArea() const noexcept {
  return (pTopRight_.x - pBottomLeft_.x) * (pTopRight_.y - pBottomLeft_.y);
}
gavrilova::rectangle_t gavrilova::Rectangle::getFrameRect() const noexcept {
  double height = pTopRight_.y - pBottomLeft_.y;
  double width = pTopRight_.x - pBottomLeft_.x;
  point_t pos{(pTopRight_.x - pBottomLeft_.x) / 2 + pBottomLeft_.x, (pTopRight_.y - pBottomLeft_.y) / 2 + pBottomLeft_.y};
  return {height, width, pos};
}
void gavrilova::Rectangle::move(const point_t& p) noexcept {
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}
void gavrilova::Rectangle::move(double difX, double difY) noexcept {
  pBottomLeft_.move(difX, difY);
  pTopRight_.move(difX, difY);
}
void gavrilova::Rectangle::scale_without_check(double k) noexcept{
  rectangle_t frameRect = getFrameRect();
  point_t center = frameRect.pos;
  pBottomLeft_.x = center.x - frameRect.width / 2 * k;
  pBottomLeft_.y = center.y - frameRect.height / 2 * k;
  pTopRight_.x = center.x + frameRect.width / 2 * k;
  pTopRight_.y = center.y + frameRect.height / 2 * k;
}
gavrilova::Shape* gavrilova::Rectangle::clone() const {
  return new Rectangle(*this);
}
