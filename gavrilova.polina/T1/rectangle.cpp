#include "rectangle.hpp"
#include "pointManip.hpp"

gavrilova::Rectangle::Rectangle(const point_t& pBottomLeft, const point_t& pTopRight):
  pBottomLeft_(pBottomLeft),
  pTopRight_(pTopRight)
{
  if (pBottomLeft.x >= pTopRight.x || pBottomLeft.y >= pTopRight.y) {
    throw std::logic_error("Invalid arguments for rectangle");
  }
}

double gavrilova::Rectangle::getArea() const
{
  return (pTopRight_.x - pBottomLeft_.x) * (pTopRight_.y - pBottomLeft_.y);
}

gavrilova::rectangle_t gavrilova::Rectangle::getFrameRect() const
{
  double height = pTopRight_.y - pBottomLeft_.y;
  double width = pTopRight_.x - pBottomLeft_.x;
  point_t pos{width / 2 + pBottomLeft_.x, height / 2 + pBottomLeft_.y};
  return {width, height, pos};
}

void gavrilova::Rectangle::move(const point_t& p)
{
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}

void gavrilova::Rectangle::move(double difX, double difY)
{
  movePoint(pBottomLeft_, difX, difY);
  movePoint(pTopRight_, difX, difY);
}

void gavrilova::Rectangle::scaleWithoutCheck(double k) noexcept
{
  rectangle_t frameRect = getFrameRect();
  point_t center = frameRect.pos;
  pBottomLeft_ = {center.x - frameRect.width / 2 * k, center.y - frameRect.height / 2 * k};
  pTopRight_ = {center.x + frameRect.width / 2 * k, center.y + frameRect.height / 2 * k};
}

gavrilova::Shape* gavrilova::Rectangle::clone() const
{
  return new Rectangle(*this);
}
