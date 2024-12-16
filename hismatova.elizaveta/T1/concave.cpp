#include "concave.hpp"
#include <iostream>
#include <cmath>
#include "base-types.hpp"
#include "triangle.hpp"

namespace hismatova
{
  concave::concave(point_t p1, point_t p2, point_t p3, point_t p4):
    p1_(p1),
    p2_(p2),
    p3_(p3),
    p4_(p4)
  {
    double area1 = triangle(p1, p2, p4).getArea();
    double area2 = triangle(p1, p3, p4).getArea();
    double area3 = triangle(p2, p3, p4).getArea();
    double area_triangle = getArea();
    if (std::fabs(area1 + area2 + area3 - area_triangle) > std::numeric_limits< double >::epsilon())
    {
      throw std::wrong_arg("4 point must be inside the triangle formed by the first three points");
    }
  }
  double concave::getArea() const
  {
    double area1 = triangle(p1_, p2_, p4_).getArea();
    double area2 = triangle(p2_, p3_, p4_).getArea();
    return area1 + area2;
  }
  void concave::move(double x, double y)
  {
    p1_.x += x;
    p1_.y += y;
    p2_.x += x;
    p2_.y += y;
    p3_.x += x;
    p3_.y += y;
    p4_.x += x;
    p4_.y += y;
  }
  rectangle_t concave::getFrameRect() const
  {
    double minX = std::min({ p1_.x, p2_.x, p3_.x, p4_.x });
    double maxX = std::max({ p1_.x, p2_.x, p3_.x, p4_.x });
    double minY = std::min({ p1_.y, p2_.y, p3_.y, p4_.y });
    double maxY = std::max({ p1_.y, p2_.y, p3_.y, p4_.y });
    return { {(minX + maxX) / 2, (minY + maxY) / 2}, maxX - minX, maxY - minY };
  }
  void concave::move(point_t point)
  {
    double dx = point.x - p4_.x;
    double dy = point.y - p4_.y;
    move(dx, dy);
  }
  void concave::scale(double index)
  {
    if (index <= 0)
    {
      std::cerr << "index must be positive\n";
      return;
    }
    point_t center = p4_;
    p1_.x = center.x + index * (p1_.x - center.x);
    p1_.y = center.y + index * (p1_.y - center.y);
    p2_.x = center.x + index * (p2_.x - center.x);
    p2_.y = center.y + index * (p2_.y - center.y);
    p3_.x = center.x + index * (p3_.x - center.x);
    p3_.y = center.y + index * (p3_.y - center.y);
  }
}
