#include "rectangle.hpp"
#include "additional-utilities.hpp"
namespace
{
  nikonov::point_t findMidPt(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    return { (rtp.x + lbp.x) / 2, (rtp.y + lbp.y) / 2 };
  }
}
nikonov::Rectangle::Rectangle(const point_t &lbp, const point_t &rtp):
  left_({ point_t{ lbp.x, rtp.y }, point_t{ lbp.x, lbp.y }, findMidPt(lbp, rtp) }),
  right_({ point_t{ rtp.x, rtp.y }, point_t{ rtp.x, lbp.y }, findMidPt(lbp, rtp) }),
  top_({ point_t{ lbp.x, rtp.y }, point_t{ rtp.x, rtp.y }, findMidPt(lbp, rtp) }),
  bot_({ point_t{ lbp.x, lbp.y }, point_t{ rtp.x, lbp.y }, findMidPt(lbp, rtp) })
{
  if (lbp.x >= rtp.x || lbp.y >= rtp.y)
  {
    throw std::logic_error("ERROR:noncorrect rectangle parameters");
  }
}
double nikonov::Rectangle::getArea() const
{
  return right_.getArea() + left_.getArea() + top_.getArea() + bot_.getArea();
}
nikonov::rectangle_t nikonov::Rectangle::getFrameRect() const
{
  double rectWidth = bot_.getFrameRect().width;
  double rectHeight = left_.getFrameRect().height;
  double rectPosX = left_.getFrameRect().pos.x + left_.getFrameRect().width / 2;
  point_t pos{ rectPosX, left_.getFrameRect().pos.y };
  return { rectWidth, rectHeight, pos };
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
  right_.move(x, y);
  left_.move(x, y);
  top_.move(x, y);
  bot_.move(x, y);
}
void nikonov::Rectangle::scale(double k) noexcept
{
  rectangle_t crntRect = getFrameRect();
  ispScale(right_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(left_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(top_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(bot_, crntRect.pos.x, crntRect.pos.y, k);
}
nikonov::Shape *nikonov::Rectangle::clone() const
{
  rectangle_t crntRect = getFrameRect();
  point_t lbp{ crntRect.pos.x - crntRect.width / 2, crntRect.pos.y - crntRect.height / 2 };
  point_t rtp{ crntRect.pos.x + crntRect.width / 2, crntRect.pos.y + crntRect.height / 2 };
  return new Rectangle(lbp, rtp);
}
