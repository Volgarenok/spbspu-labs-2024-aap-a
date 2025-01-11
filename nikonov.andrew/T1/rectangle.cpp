#include "rectangle.hpp"
#include <algorithm>
#include "additional-utilities.hpp"
namespace
{
  struct RectangleData
  {
    double minX;
    double maxX;
    double minY;
    double maxY;
    double width;
    double height;
    RectangleData(const nikonov::point_t &lbp, const nikonov::point_t &rtp):
      minX(std::min(lbp.x, rtp.x)),
      maxX(std::max(lbp.x, rtp.x)),
      minY(std::min(lbp.y, rtp.y)),
      maxY(std::max(lbp.y, rtp.y)),
      width(maxX - minX),
      height(maxY - minY)
    {}
  };
  nikonov::Triangle findLeftTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
  nikonov::Triangle findRightTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
  nikonov::Triangle findTopTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
  nikonov::Triangle findBottomTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp);
}
nikonov::Rectangle::Rectangle(const point_t &lbp, const point_t &rtp):
  left_tgl_(findLeftTgl(lbp, rtp)),
  right_tgl_(findRightTgl(lbp, rtp)),
  top_tgl_(findTopTgl(lbp, rtp)),
  bot_tgl_(findBottomTgl(lbp, rtp))
{
  if (lbp.x >= rtp.x || lbp.y >= rtp.y)
  {
    throw std::logic_error("ERROR:noncorrect rectangle parameters");
  }
}
double nikonov::Rectangle::getArea() const noexcept
{
  return right_tgl_.getArea() + left_tgl_.getArea() + top_tgl_.getArea() + bot_tgl_.getArea();
}
nikonov::rectangle_t nikonov::Rectangle::getFrameRect() const noexcept
{
  double minY = left_tgl_.getFrameRect().pos.y - left_tgl_.getFrameRect().height / 2;
  double minX = left_tgl_.getFrameRect().pos.x - left_tgl_.getFrameRect().width / 2;
  double rectWidth = bot_tgl_.getFrameRect().width;
  double rectHeight = left_tgl_.getFrameRect().height;
  point_t pos = point_t({ minX + (rectWidth / 2), minY + (rectHeight / 2) });
  return rectangle_t({ rectWidth, rectHeight, pos });
}
void nikonov::Rectangle::move(const point_t &newPos) noexcept
{
  rectangle_t crntRect = getFrameRect();
  double diffX = newPos.x - crntRect.pos.x;
  double diffY = newPos.y - crntRect.pos.y;
  move(diffX, diffY);
}
void nikonov::Rectangle::move(double x, double y) noexcept
{
  right_tgl_.move(x, y);
  left_tgl_.move(x, y);
  top_tgl_.move(x, y);
  bot_tgl_.move(x, y);
}
void nikonov::Rectangle::scale(double k) noexcept
{
  rectangle_t crntRect = getFrameRect();
  ispScale(&right_tgl_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&left_tgl_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&top_tgl_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&bot_tgl_, crntRect.pos.x, crntRect.pos.y, k);
}
namespace
{
  nikonov::Triangle findLeftTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    RectangleData data(lbp, rtp);
    nikonov::point_t topP({ data.minX, data.maxY });
    nikonov::point_t botP({ data.minX, data.minY });
    nikonov::point_t midP({ data.minX + data.width / 2, data.minY + data.height / 2 });
    return nikonov::Triangle({ topP, botP, midP });
  }
  nikonov::Triangle findRightTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    RectangleData data(lbp, rtp);
    nikonov::point_t topP({ data.maxX, data.maxY });
    nikonov::point_t botP({ data.maxX, data.minY });
    nikonov::point_t midP({ data.minX + data.width / 2, data.minY + data.height / 2 });
    return nikonov::Triangle({ topP, botP, midP });
  }
  nikonov::Triangle findTopTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    RectangleData data(lbp, rtp);
    nikonov::point_t topP1({ data.minX, data.maxY });
    nikonov::point_t topP2({ data.maxX, data.maxY });
    nikonov::point_t midP({ data.minX + data.width / 2, data.minY + data.height / 2 });
    return nikonov::Triangle({ topP1, topP2, midP });
  }
  nikonov::Triangle findBottomTgl(const nikonov::point_t &lbp, const nikonov::point_t &rtp)
  {
    RectangleData data(lbp, rtp);
    nikonov::point_t botP1({ data.minX, data.minY });
    nikonov::point_t botP2({ data.maxX, data.minY });
    nikonov::point_t midP({ data.minX + data.width / 2, data.minY + data.height / 2 });
    return nikonov::Triangle({ botP1, botP2, midP });
  }
}
