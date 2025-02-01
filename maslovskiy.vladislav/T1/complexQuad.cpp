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
    point_t intersectionPoint = findIntersectionPoint(vertexA_, vertexB_, vertexC_, vertexD_);
    double firstTriangleArea = calculateTriangleArea(vertexA_, vertexD_, intersectionPoint);
    double secondTriangleArea = calculateTriangleArea(intersectionPoint, vertexB_, vertexC_);
    return firstTriangleArea + secondTriangleArea;
  }
  rectangle_t ComplexQuad::getFrameRect() const
  {
    double left_border = std::fmin(std::fmin(std::fmin(vertexA_.x, vertexB_.x), vertexC_.x), vertexD_.x);
    double right_border = std::fmax(std::fmax(std::fmax(vertexA_.x, vertexB_.x), vertexC_.x), vertexD_.x);
    double upper_border = std::fmax(std::fmax(std::fmax(vertexA_.y, vertexB_.y), vertexC_.y), vertexD_.y);
    double lower_border = std::fmin(std::fmin(std::fmin(vertexA_.y, vertexB_.y), vertexC_.y), vertexD_.y);
    double width = right_border - left_border;
    double height = upper_border - lower_border;
    point_t center{left_border + width / 2, lower_border + height / 2};
    return rectangle_t{width, height, center};
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
