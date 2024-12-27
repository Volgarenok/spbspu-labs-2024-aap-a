#include "rectangle.hpp"
#include <iostream>
#include "base-types.hpp"
nikonov::Rectangle::Rectangle(point_t lbp, point_t rtp):
  lbp_(lbp),
  rtp_(rtp)
{}
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
void nikonov::Rectangle::move(point_t newPos)
{
  rectangle_t crntRect = getFrameRect();
  double diffX = newPos.x - crntRect.pos.x;
  double diffY = newPos.y - crntRect.pos.y;
  move(diffX, diffY);
}
void nikonov::Rectangle::move(double x, double y)
{
  lbp_.x += x;
  rtp_.x += x;
  lbp_.y += y;
  rtp_.y += y;
}
void nikonov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    std::cerr << "Scale denied: k must be more than zero\n";
    return;
  }
  rectangle_t crntRect = getFrameRect();
  crntRect.width *= k;
  crntRect.height *= k;
  double newlbpX = crntRect.pos.x - crntRect.width / 2;
  double newlbpY = crntRect.pos.y - crntRect.height / 2;
  double newrtpX = crntRect.pos.x + crntRect.width / 2;
  double newrtpY = crntRect.pos.y + crntRect.height / 2;
  lbp_ = point_t({ newlbpX, newlbpY });
  rtp_ = point_t({ newrtpX, newrtpY });
}
