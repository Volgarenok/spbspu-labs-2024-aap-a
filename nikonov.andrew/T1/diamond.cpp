#include "diamond.hpp"
#include <cmath>
#include "additional-utilities.hpp"
namespace
{
  using namespace nikonov;
  point_t findTop(const point_t &p1, const point_t &p2, const point_t &p3);
  point_t findMid(const point_t &p1, const point_t &p2, const point_t &p3);
  point_t findRight(const point_t &p1, const point_t &p2, const point_t &p3);
  bool isEqualPoint(const point_t &p1, const point_t &p2);
  Triangle findLeftTopTgl(const point_t &p1, const point_t &p2, const point_t &p3);
  Triangle findLeftBotTgl(const point_t &p1, const point_t &p2, const point_t &p3);
  Triangle findRightTopTgl(const point_t &p1, const point_t &p2, const point_t &p3);
  Triangle findRightBotTgl(const point_t &p1, const point_t &p2, const point_t &p3);
  struct BaseTglPoints
  {
    point_t topP;
    point_t midP;
    point_t rightP;
    BaseTglPoints(const point_t &p1, const point_t &p2, const point_t &p3):
      topP(findTop(p1, p2, p3)),
      midP(findMid(p1, p2, p3)),
      rightP(findRight(p1, p2, p3))
    {}
  };
}
nikonov::Diamond::Diamond(const point_t &p1, const point_t &p2, const point_t &p3):
  lt_tgl_(findLeftTopTgl(p1, p2, p3)),
  lb_tgl_(findLeftBotTgl(p1, p2, p3)),
  rt_tgl_(findRightTopTgl(p1, p2, p3)),
  rb_tgl_(findRightBotTgl(p1, p2, p3))
{
  BaseTglPoints data(p1, p2, p3);
  if (!(data.topP.x == data.midP.x && data.rightP.y == data.midP.y))
  {
    throw std::logic_error("ERROR:noncorrect diamond parameters");
  }
}
double nikonov::Diamond::getArea() const noexcept
{
  return lt_tgl_.getArea() + lb_tgl_.getArea() + rt_tgl_.getArea() + rb_tgl_.getArea();
}
nikonov::rectangle_t nikonov::Diamond::getFrameRect() const noexcept
{
  double width = lt_tgl_.getFrameRect().width * 2;
  double height = lt_tgl_.getFrameRect().height * 2;
  point_t tglCenter = lt_tgl_.getFrameRect().pos;
  point_t pos = point_t({ tglCenter.x + (width / 4), tglCenter.y - (height / 4) });
  return rectangle_t({ width, height, pos });
}
void nikonov::Diamond::move(const point_t &newPos) noexcept
{
  rectangle_t crntRect = getFrameRect();
  double diffX = newPos.x - crntRect.pos.x;
  double diffY = newPos.y - crntRect.pos.y;
  move(diffX, diffY);
}
void nikonov::Diamond::move(double x, double y) noexcept
{
  lt_tgl_.move(x, y);
  lb_tgl_.move(x, y);
  rt_tgl_.move(x, y);
  rb_tgl_.move(x, y);
}
void nikonov::Diamond::scale(double k) noexcept
{
  rectangle_t crntRect = getFrameRect();
  ispScale(&lt_tgl_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&lb_tgl_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&rt_tgl_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(&rb_tgl_, crntRect.pos.x, crntRect.pos.y, k);
}
namespace
{
  point_t findTop(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    double maxY = std::max(std::max(p1.y, p2.y), p3.y);
    point_t result({ 0, 0 });
    size_t maxCnt = (p1.y == maxY) + (p2.y == maxY) + (p3.y == maxY);
    if (maxCnt > 1)
    {
      throw std::logic_error("non-correct parameters");
    }
    return (p1.y == maxY) ? p1 : (p2.y == maxY) ? p2 : p3;
  }
  point_t findMid(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    point_t topP = findTop(p1, p2, p3);
    if (p1.y < topP.y && p1.x == topP.x)
    {
      return p1;
    }
    else if (p2.y < topP.y && p2.x == topP.x)
    {
      return p2;
    }
    else if (p3.y < topP.y && p3.x == topP.x)
    {
      return p3;
    }
    else
    {
      throw std::logic_error("non-correct parameters");
    }
  }
  bool isEqualPoint(const point_t &p1, const point_t &p2)
  {
    return (p1.x == p2.x) && (p1.y == p2.y);
  }
  point_t findRight(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    point_t topP = findTop(p1, p2, p3);
    point_t midP = findMid(p1, p2, p3);
    point_t edgeP({ 0, 0 });
    if (!isEqualPoint(p1, topP) && !isEqualPoint(p1, midP))
    {
      edgeP = p1;
    }
    else if (!isEqualPoint(p2, topP) && !isEqualPoint(p2, midP))
    {
      edgeP = p2;
    }
    else
    {
      edgeP = p3;
    }
    if (edgeP.x < midP.x)
    {
      edgeP.x = 2 * midP.x - edgeP.x;
    }
    return edgeP;
  }
  Triangle findLeftTopTgl(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    BaseTglPoints data(p1, p2, p3);
    point_t leftP({ 2 * data.midP.x - data.rightP.x, data.midP.y });
    return Triangle({ data.topP, data.midP, leftP });
  }
  Triangle findLeftBotTgl(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    BaseTglPoints data(p1, p2, p3);
    point_t botP({ data.topP.x, 2 * data.midP.y - data.topP.y });
    point_t leftP({ 2 * data.midP.x - data.rightP.x, data.midP.y });
    return Triangle({ botP, data.midP, leftP });
  }
  Triangle findRightTopTgl(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    BaseTglPoints data(p1, p2, p3);
    return Triangle({ data.topP, data.midP, data.rightP });
  }
  Triangle findRightBotTgl(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    BaseTglPoints data(p1, p2, p3);
    point_t botP({ data.topP.x, 2 * data.midP.y - data.topP.y });
    return Triangle({ botP, data.midP, data.rightP });
  }
}
