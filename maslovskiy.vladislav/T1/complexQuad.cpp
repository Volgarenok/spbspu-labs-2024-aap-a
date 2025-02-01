#include "complexQuad.hpp"
#include <algorithm>
#include "geomFun.hpp"
namespace maslovskiy
{
  ComplexQuad::ComplexQuad(point_t vertexA, point_t vertexB, point_t vertexC, point_t vertexD):
    vertexA_(vertexA),
    vertexB_(vertexB),
    vertexC_(vertexC),
    vertexD_(vertexD)
  {
  }
  double ComplexQuad::getArea() const
  {
    point_t center = getFrameRect().pos;
    return calculateTriangleArea(vertexA_, vertexD_, center) + calculateTriangleArea(vertexB_, vertexC_, center);
  }

  rectangle_t ComplexQuad::getFrameRect() const
  {
    double left = std::min({vertexA_.x, vertexB_.x, vertexC_.x, vertexD_.x});
    double right = std::max({vertexA_.x, vertexB_.x, vertexC_.x, vertexD_.x});
    double bottom = std::min({vertexA_.y, vertexB_.y, vertexC_.y, vertexD_.y});
    double top = std::max({vertexA_.y, vertexB_.y, vertexC_.y, vertexD_.y});
    point_t center = {left + (right - left) / 2, bottom + (top - bottom) / 2};
    return {right - left, top - bottom, center};
  }
  void ComplexQuad::move(point_t newPos)
  {
    point_t currentCenter = getFrameRect().pos;
    double moveX = newPos.x - currentCenter.x;
    double moveY = newPos.y - currentCenter.y;
    vertexA_.x += moveX;
    vertexA_.y += moveY;
    vertexB_.x += moveX;
    vertexB_.y += moveY;
    vertexC_.x += moveX;
    vertexC_.y += moveY;
    vertexD_.x += moveX;
    vertexD_.y += moveY;
  }
  void ComplexQuad::move(double moveX, double moveY)
  {
    vertexA_.x += moveX;
    vertexA_.y += moveY;
    vertexB_.x += moveX;
    vertexB_.y += moveY;
    vertexC_.x += moveX;
    vertexC_.y += moveY;
    vertexD_.x += moveX;
    vertexD_.y += moveY;
  }
  void ComplexQuad::scale(double factor)
  {
    point_t currentCenter = getFrameRect().pos;
    vertexA_.x = currentCenter.x - (currentCenter.x - vertexA_.x) * factor;
    vertexA_.y = currentCenter.y - (currentCenter.y - vertexA_.y) * factor;
    vertexB_.x = currentCenter.x - (currentCenter.x - vertexB_.x) * factor;
    vertexB_.y = currentCenter.y - (currentCenter.y - vertexB_.y) * factor;
    vertexC_.x = currentCenter.x - (currentCenter.x - vertexC_.x) * factor;
    vertexC_.y = currentCenter.y - (currentCenter.y - vertexC_.y) * factor;
    vertexD_.x = currentCenter.x - (currentCenter.x - vertexD_.x) * factor;
    vertexD_.y = currentCenter.y - (currentCenter.y - vertexD_.y) * factor;
  }
}
