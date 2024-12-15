#include "triangle.hpp"
#include "geomFun.hpp"
#include <algorithm>
#include <stdexcept>

maslovskiy::Triangle::Triangle(point_t vertexA, point_t vertexB, point_t vertexC)
    : vertexA_(vertexA),
      vertexB_(vertexB),
      vertexC_(vertexC)
{
  if (!isCorrectTriangle(vertexA_, vertexB_, vertexC_))
  {
    throw std::logic_error("Invalid triangle vertices");
  }
}
double maslovskiy::Triangle::getArea() const
{
  return calculateTriangleArea(vertexA_, vertexB_, vertexC_);
}
maslovskiy::rectangle_t maslovskiy::Triangle::getFrameRect() const
{
  double minX = std::min({vertexA_.x, vertexB_.x, vertexC_.x});
  double maxX = std::max({vertexA_.x, vertexB_.x, vertexC_.x});
  double minY = std::min({vertexA_.y, vertexB_.y, vertexC_.y});
  double maxY = std::max({vertexA_.y, vertexB_.y, vertexC_.y});
  rectangle_t frameRect;
  frameRect.width = maxX - minX;
  frameRect.height = maxY - minY;
  frameRect.pos = {minX + frameRect.width / 2, minY + frameRect.height / 2};

  return frameRect;
}
void maslovskiy::Triangle::move(point_t newPos)
{
  point_t currentCenter = getFrameRect().pos;
  double dx = newPos.x - currentCenter.x;
  double dy = newPos.y - currentCenter.y;
  move(dx, dy);
}
void maslovskiy::Triangle::move(double dx, double dy)
{
  vertexA_.x += dx;
  vertexA_.y += dy;
  vertexB_.x += dx;
  vertexB_.y += dy;
  vertexC_.x += dx;
  vertexC_.y += dy;
}
void maslovskiy::Triangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::logic_error("Scaling factor must be positive");
  }
  point_t center = getFrameRect().pos;
  vertexA_.x = center.x + (vertexA_.x - center.x) * factor;
  vertexA_.y = center.y + (vertexA_.y - center.y) * factor;
  vertexB_.x = center.x + (vertexB_.x - center.x) * factor;
  vertexB_.y = center.y + (vertexB_.y - center.y) * factor;
  vertexC_.x = center.x + (vertexC_.x - center.x) * factor;
  vertexC_.y = center.y + (vertexC_.y - center.y) * factor;
}
