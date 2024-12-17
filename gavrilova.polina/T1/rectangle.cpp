#include "rectangle.hpp"
#include <iostream>
#include "base-types.hpp"

gavrilova::Rectangle::Rectangle(point_t pBottomLeft, point_t pTopRight):
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
double gavrilova::Rectangle::getArea() const {
  return (pTopRight_.x - pBottomLeft_.x) * (pTopRight_.y - pBottomLeft_.y);
}
gavrilova::rectangle_t gavrilova::Rectangle::getFrameRect() const {
  rectangle_t resultRect;
  resultRect.height = pTopRight_.y - pBottomLeft_.y;
  resultRect.width = pTopRight_.x - pBottomLeft_.x;
  resultRect.pos.x = (pTopRight_.x - pBottomLeft_.x) / 2 + pBottomLeft_.x;
  resultRect.pos.y = (pTopRight_.y - pBottomLeft_.y) / 2 + pBottomLeft_.y;
  return resultRect;
}
void gavrilova::Rectangle::move(point_t p) {
  point_t center = getFrameRect().pos;
  double difX = center.x - p.x;
  double difY = center.y - p.y;
  pBottomLeft_.x -= difX;
  pBottomLeft_.y -= difY;
  pTopRight_.x -= difX;
  pTopRight_.y -= difY;
}
void gavrilova::Rectangle::move(double difX, double difY) {
  pBottomLeft_.x += difX;
  pBottomLeft_.y += difY;
  pTopRight_.x += difX;
  pTopRight_.y += difY;
}
void gavrilova::Rectangle::scale(double k) {
  rectangle_t frameRect = getFrameRect();
  point_t center = frameRect.pos;
  pBottomLeft_.x = center.x - frameRect.width / 2 * k;
  pBottomLeft_.y = center.y - frameRect.height / 2 * k;
  pTopRight_.x = center.x + frameRect.width / 2 * k;
  pTopRight_.y = center.y + frameRect.height / 2 * k;
}

