#include "rectangle.hpp"
#include <cmath>
#include "additional-utilities.hpp"
namespace
{
  nikonov::Triangle findLeftTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
  nikonov::Triangle findRightTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
  nikonov::Triangle findTopTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
  nikonov::Triangle findBottomTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
}
nikonov::Rectangle::Rectangle(const point_t &lbp, const point_t &rtp):
  left_(findLeftTgl(lbp, rtp)),
  right_(findRightTgl(lbp, rtp)),
  top_(findTopTgl(lbp, rtp)),
  bot_(findBottomTgl(lbp, rtp))
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
  double minY = left_.getFrameRect().pos.y - left_.getFrameRect().height / 2;
  double minX = left_.getFrameRect().pos.x - left_.getFrameRect().width / 2;
  double rectWidth = bot_.getFrameRect().width;
  double rectHeight = left_.getFrameRect().height;
  point_t pos = point_t({ minX + (rectWidth / 2), minY + (rectHeight / 2) });
  return rectangle_t({ rectWidth, rectHeight, pos });
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
  ispScale(&right_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&left_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&top_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&bot_, crntRect.pos.x, crntRect.pos.y, k);
}
nikonov::Shape *nikonov::Rectangle::clone() const
{
  rectangle_t crntRect = getFrameRect();
  point_t lbp({ crntRect.pos.x - crntRect.width / 2, crntRect.pos.y - crntRect.height / 2 });
  point_t rtp({ crntRect.pos.x + crntRect.width / 2, crntRect.pos.y + crntRect.height / 2 });
  return new Rectangle(lbp, rtp);
}
namespace
{
  nikonov::Triangle findLeftTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    nikonov::point_t topP({ lbp.x, rtp.y });
    nikonov::point_t botP({ lbp.x, lbp.y });
    nikonov::point_t midP({ lbp.x + (rtp.x - lbp.x) / 2, lbp.y + (rtp.y - lbp.y) / 2 });
    return nikonov::Triangle({ topP, botP, midP });
  }
  nikonov::Triangle findRightTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    nikonov::point_t topP({ rtp.x, rtp.y });
    nikonov::point_t botP({ rtp.x, lbp.y });
    nikonov::point_t midP({ lbp.x + (rtp.x - lbp.x) / 2, lbp.y + (rtp.y - lbp.y) / 2 });
    return nikonov::Triangle({ topP, botP, midP });
  }
  nikonov::Triangle findTopTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    nikonov::point_t topP1({ lbp.x, rtp.y });
    nikonov::point_t topP2({ rtp.x, rtp.y });
    nikonov::point_t midP({ lbp.x + (rtp.x - lbp.x) / 2, lbp.y + (rtp.y - lbp.y) / 2 });
    return nikonov::Triangle({ topP1, topP2, midP });
  }
  nikonov::Triangle findBottomTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    nikonov::point_t botP1({ lbp.x, lbp.y});
    nikonov::point_t botP2({  rtp.x, lbp.y });
    nikonov::point_t midP({ lbp.x + (rtp.x - lbp.x) / 2, lbp.y + (rtp.y - lbp.y) / 2 });
    return nikonov::Triangle({ botP1, botP2, midP });
  }
}
