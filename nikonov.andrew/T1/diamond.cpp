#include "diamond.hpp"
#include <iostream>
#include <exception>
#include "base-types.hpp"
namespace
{
  nikonov::point_t findTop(const nikonov::point_t &p1, const nikonov::point_t &p2, const nikonov::point_t &p3);
  nikonov::point_t findMid(const nikonov::point_t &p1, const nikonov::point_t &p2, const nikonov::point_t &p3);
  nikonov::point_t findEdge(const nikonov::point_t &p1, const nikonov::point_t &p2, const nikonov::point_t &p3);
  bool isEqualPoint(const nikonov::point_t &p1, const nikonov::point_t &p2);
}
nikonov::Diamond::Diamond(const point_t& p1, const point_t& p2, const point_t& p3)
{
  point_t topP({ 0, 0 });
  point_t midP({ 0, 0 });
  try
  {
    topP = findTop(p1, p2, p3);
    midP = findMid(p1, p2, p3);
  }
  catch (const std::exception &e)
  {
    throw std::logic_error("ERROR:noncorrect diamond parameters");
  }
  point_t edgeP = findEdge(p1, p2, p3);
  if (!(topP.x == midP.x && edgeP.y == midP.y))
  {
    throw std::logic_error("ERROR:noncorrect diamond parameters");
  }
  topP_ = topP;
  midP_ = midP;
  rightP_ = edgeP;
}
double nikonov::Diamond::getArea() const
{
  return (rightP_.x - midP_.x) * (topP_.y - midP_.y) * 2;
}
nikonov::rectangle_t nikonov::Diamond::getFrameRect() const
{
  point_t rtp({ rightP_.x, topP_.y });
  point_t lbp({ 2 * midP_.x - rightP_.x, 2 * midP_.y - topP_.y });
  double width = rtp.x - lbp.x;
  double height = rtp.y - lbp.y;
  point_t pos = point_t({ lbp.x + (width / 2), lbp.y + (height / 2) });
  return rectangle_t({ width, height, pos });
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
  movePoint(topP_, x, y);
  movePoint(midP_, x, y);
  movePoint(rightP_, x, y);
}
void nikonov::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Scale denied: k must be more than zero");
  }
  rectangle_t crntRect = getFrameRect();
  crntRect.width *= k;
  crntRect.height *= k;
  double newTopX = crntRect.pos.x + crntRect.width / 2;
  double newTopY = crntRect.pos.y + crntRect.height / 2;
  double newRightX = crntRect.pos.x + crntRect.width / 2;
  double newRightY = crntRect.pos.y + crntRect.height / 2;
  topP_ = point_t({ newTopX, newTopY });
  rightP_ = point_t({ newRightX, newRightY });
}
namespace
{
  nikonov::point_t findTop(const nikonov::point_t &p1, const nikonov::point_t &p2, const nikonov::point_t &p3)
  {
    if (p1.y > p2.y && p1.y > p3.y)
    {
      return p1;
    }
    else if (p2.y > p1.y && p2.y > p3.y)
    {
      return p2;
    }
    else if (p3.y > p1.y && p3.y > p2.y)
    {
      return p3;
    }
    else
    {
      throw std::logic_error("non-correct parameters");
    }
  }
  nikonov::point_t findMid(const nikonov::point_t &p1, const nikonov::point_t &p2, const nikonov::point_t &p3)
  {
    nikonov::point_t topP = findTop(p1, p2, p3);
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
  bool isEqualPoint(const nikonov::point_t &p1, const nikonov::point_t &p2)
  {
    return (p1.x == p2.x) && (p1.y == p2.y);
  }
  nikonov::point_t findEdge(const nikonov::point_t &p1, const nikonov::point_t &p2, const nikonov::point_t &p3)
  {
    nikonov::point_t topP = findTop(p1, p2, p3);
    nikonov::point_t midP = findMid(p1, p2, p3);
    nikonov::point_t edgeP({ 0, 0 });
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
}
