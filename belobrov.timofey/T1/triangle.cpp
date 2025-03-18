#include "triangle.hpp"
#include "geomFunc.hpp"

namespace belobrov
{
  Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : v1_{x1, y1}, v2_{x2, y2}, v3_{x3, y3}
  {
    if (!isCorrectTriangle(v1_, v2_, v3_)) {
      throw std::invalid_argument("Invalid triangle");
    }
  }

  double Triangle::getArea() const
  {
    return calculateTriangleArea(v1_, v2_, v3_);
  }

  rectangle_t Triangle::getFrameRect() const
  {
    double minX = std::min({v1_.x, v2_.x, v3_.x});
    double maxX = std::max({v1_.x, v2_.x, v3_.x});
    double minY = std::min({v1_.y, v2_.y, v3_.y});
    double maxY = std::max({v1_.y, v2_.y, v3_.y});

    return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2} };
  }

  void Triangle::move(const point_t& point)
  {
    point_t curCenter = getFrameRect().pos;
    double dx = point.x - curCenter.x;
    double dy = point.y - curCenter.y;
    move(dx, dy);
  }

  void Triangle::move(double dx, double dy)
  {
    v1_.x += dx;
    v1_.y += dy;
    v2_.x += dx;
    v2_.y += dy;
    v3_.x += dx;
    v3_.y += dy;
  }

  void Triangle::scale(double k)
  {
    if (k <= 0) {
      throw std::invalid_argument("Scaling factor must be positive");
    }

    point_t center = getFrameRect().pos;

    v1_.x = center.x + (v1_.x - center.x) * k;
    v1_.y = center.y + (v1_.y - center.y) * k;
    v2_.x = center.x + (v2_.x - center.x) * k;
    v2_.y = center.y + (v2_.y - center.y) * k;
    v3_.x = center.x + (v3_.x - center.x) * k;
    v3_.y = center.y + (v3_.y - center.y) * k;
  }
}
