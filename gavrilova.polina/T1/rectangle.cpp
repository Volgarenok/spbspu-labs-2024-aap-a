#include "rectangle.hpp"
#include "base-types.hpp"

gavrilova::Rectangle::Rectangle(point_t pBottomLeft, point_t pTopRight):
  pBottomLeft_(pBottomLeft), pTopRight_(pTopRight) {}
double gavrilova::Rectangle::getArea() const {
  return (pTopRight_.x - pBottomLeft_.x) * (pTopRight_.y - pBottomLeft_.y);
}
gavrilova::rectangle_t gavrilova::Rectangle::getFrameRect() const {
  rectangle_t resultRect;
  resultRect.height = pTopRight_.y - pBottomLeft_.y;
  resultRect.width = pTopRight_.x - pBottomLeft_.x;
  resultRect.pos.x = (pTopRight_.x - pBottomLeft_.x)/2;
  resultRect.pos.y = (pTopRight_.y - pBottomLeft_.y)/2;
  return resultRect;
}
void gavrilova::Rectangle::move(point_t p) {
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  pBottomLeft_.x += difX;
  pBottomLeft_.y += difY;
  pTopRight_.x += difX;
  pTopRight_.y += difY;
}
void gavrilova::Rectangle::move(double difX, double difY) {
  pBottomLeft_.x += difX;
  pBottomLeft_.y += difY;
  pTopRight_.x += difX;
  pTopRight_.y += difY;
}
void gavrilova::Rectangle::scale(double k) {
  point_t center = getFrameRect().pos;
  pBottomLeft_.x = center.x - getFrameRect().width / 2 * k;
  pBottomLeft_.y = center.y - getFrameRect().height / 2 * k;
  pTopRight_.x = center.x + getFrameRect().width / 2 * k;
  pTopRight_.y = center.y + getFrameRect().height / 2 * k;
}

