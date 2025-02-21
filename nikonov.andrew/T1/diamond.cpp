#include "diamond.hpp"
#include "additional-utilities.hpp"
namespace
{
  using namespace nikonov;
  point_t findTop(const point_t &p1, const point_t &p2, const point_t &p3);
  point_t findMid(const point_t &p1, const point_t &p2, const point_t &p3);
  point_t findRight(const point_t &p1, const point_t &p2, const point_t &p3);
  point_t findLeft(const point_t &p1, const point_t &p2, const point_t &p3);
  point_t findBot(const point_t &p1, const point_t &p2, const point_t &p3);
  bool isEqualPoint(const point_t &p1, const point_t &p2);
}
nikonov::Diamond::Diamond(const point_t &p1, const point_t &p2, const point_t &p3):
  lt_({ findTop(p1, p2, p3), findMid(p1, p2, p3), findLeft(p1, p2, p3) }),
  lb_({ findBot(p1, p2, p3), findMid(p1, p2, p3), findLeft(p1, p2, p3) }),
  rt_({ findTop(p1, p2, p3), findMid(p1, p2, p3), findRight(p1, p2, p3) }),
  rb_({ findBot(p1, p2, p3), findMid(p1, p2, p3), findRight(p1, p2, p3) })
{
  point_t topP = findTop(p1, p2, p3);
  point_t midP = findMid(p1, p2, p3);
  point_t rightP = findRight(p1, p2, p3);
  if (!(topP.x == midP.x && rightP.y == midP.y))
  {
    throw std::logic_error("ERROR:noncorrect diamond parameters");
  }
}
double nikonov::Diamond::getArea() const
{
  return lt_.getArea() + lb_.getArea() + rt_.getArea() + rb_.getArea();
}
nikonov::rectangle_t nikonov::Diamond::getFrameRect() const
{
  double width = lt_.getFrameRect().width * 2;
  double height = lt_.getFrameRect().height * 2;
  point_t tglCenter = lt_.getFrameRect().pos;
  point_t pos = point_t({ tglCenter.x + (width / 4), tglCenter.y - (height / 4) });
  return { width, height, pos };
}
void nikonov::Diamond::move(const point_t &newPos)
{
  rectangle_t crntRect = getFrameRect();
  double diffX = newPos.x - crntRect.pos.x;
  double diffY = newPos.y - crntRect.pos.y;
  move(diffX, diffY);
}
void nikonov::Diamond::move(double x, double y)
{
  lt_.move(x, y);
  lb_.move(x, y);
  rt_.move(x, y);
  rb_.move(x, y);
}
void nikonov::Diamond::scale(double k) noexcept
{
  rectangle_t crntRect = getFrameRect();
  ispScale(lt_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(lb_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(rt_, crntRect.pos.x, crntRect.pos.y, k);
  ispScale(rb_, crntRect.pos.x, crntRect.pos.y, k);
}
nikonov::Shape *nikonov::Diamond::clone() const
{
  rectangle_t crntRect = getFrameRect();
  point_t topP{ crntRect.pos.x, crntRect.pos.y + crntRect.height / 2 };
  point_t midP{ crntRect.pos.x, crntRect.pos.y };
  point_t rightP{ crntRect.pos.x + crntRect.width / 2, crntRect.pos.y};
  return new Diamond{ topP, midP, rightP };
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
    throw std::logic_error("non-correct parameters");
  }
  bool isEqualPoint(const point_t &p1, const point_t &p2)
  {
    return (p1.x == p2.x) && (p1.y == p2.y);
  }
  point_t findRight(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    point_t topP = findTop(p1, p2, p3);
    point_t midP = findMid(p1, p2, p3);
    point_t edgeP{ 0, 0 };
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
  point_t findLeft(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    return { 2 * findMid(p1, p2, p3).x - findRight(p1, p2, p3).x, findMid(p1, p2, p3).y };
  }
  point_t findBot(const point_t &p1, const point_t &p2, const point_t &p3)
  {
    return { findTop(p1, p2, p3).x, 2 * findMid(p1, p2, p3).y - findTop(p1, p2, p3).y };
  }
}
