#include "rectangle.hpp"
#include <stdexcept>
#include "additional-utilities.hpp"
#include "base-types.hpp"
nikonov::Rectangle::Rectangle(const point_t &lbp, const point_t &rtp):
  lbp_(lbp),
  rtp_(rtp)
{
  if (lbp.x >= rtp.x || lbp.y >= rtp.y)
  {
    throw std::logic_error("ERROR:noncorrect rectangle parameters");
  }
}
double nikonov::Rectangle::getArea() const
{
  return ((rtp_.x - lbp_.x) * (rtp_.y - lbp_.y));
}
nikonov::rectangle_t nikonov::Rectangle::getFrameRect() const
{
  double width = rtp_.x - lbp_.x;
  double height = rtp_.y - lbp_.y;
  point_t pos = point_t({ lbp_.x + (width / 2), lbp_.y + (height / 2) });
  return rectangle_t({ width, height, pos });
}
void nikonov::Rectangle::move(const point_t &newPos)
{
  rectangle_t crntRect = getFrameRect();
  double diffX = newPos.x - crntRect.pos.x;
  double diffY = newPos.y - crntRect.pos.y;
  move(diffX, diffY);
}
void nikonov::Rectangle::move(double x, double y)
{
  movePoint(lbp_, x, y);
  movePoint(rtp_, x, y);
}
void nikonov::Rectangle::scale(double k)
{
  rectangle_t crntRect = getFrameRect();
  scalePoint(lbp_, crntRect.pos, k);
  scalePoint(rtp_, crntRect.pos, k);
}