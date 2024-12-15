#include "diamond.hpp"
#include <iostream>
#include "base-types.hpp"
nikonov::Diamond::Diamond(point_t topP, point_t midP, point_t rightP):
  topP_(topP),
  rightP_(rightP),
  midP_(midP)
{}
double  nikonov::Diamond::getArea() const
{
  rectangle_t tempRect = getFrameRect();
  return (tempRect.height * tempRect.width) / 2;
}
nikonov::rectangle_t nikonov::Diamond::getFrameRect() const
{
  point_t rtp(rightP_.x, topP_.y);
  point_t lbp(2 * midP_.x - rightP_.x, 2 * midP_.y - topP_.y);
  return rectangle_t(lbp, rtp);
}
void nikonov::Diamond::move(point_t newPos)
{
  rectangle_t crntRect = getFrameRect();
  double  diffX = newPos.x - crntRect.pos.x;
  double  diffY = newPos.y - crntRect.pos.y;
  move(diffX, diffY);
}
void nikonov::Diamond::move(double  x, double  y)
{
  topP_.x += x;
  midP_.x += x;
  rightP_.x += x;
  topP_.y += y;
  midP_.y += y;
  rightP_.y += y;
}
void nikonov::Diamond::scale(double  k)
{
  if (k <= 0)
  {
    std::cerr << "Scale denied: k must be more than zero\n";
    return;
  }
  rectangle_t crntRect = getFrameRect();
  crntRect.width *= k;
  crntRect.height *= k;
  double  newTopX = crntRect.pos.x + crntRect.width / 2;
  double  newTopY = crntRect.pos.y + crntRect.height / 2;
  double  newRightX = crntRect.pos.x + crntRect.width / 2;
  double  newRightY = crntRect.pos.y + crntRect.height / 2;
  topP_ = point_t(newTopX, newTopY);
  rightP_ = point_t(newRightX, newRightY);
}
