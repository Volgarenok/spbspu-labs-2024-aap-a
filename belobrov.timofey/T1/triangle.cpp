#include "triangle.hpp"

namespace belobrov
{
  Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : v1_{x1, y1}, v2_{x2, y2}, v3_{x3, y3}
  {
    double side1 = std::hypot(x2 - x1, y2 - y1);
    double side2 = std::hypot(x3 - x2, y3 - y2);
    double side3 = std::hypot(x3 - x1, y3 - y1);

    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
    {
      throw std::invalid_argument("Invalid triangle");
    }
  }

  double Triangle::getArea() const
  {
    return 0.5 * std::abs(v1_.x * (v2_.y - v3_.y) + v2_.x * (v3_.y - v1_.y) + v3_.x * (v1_.y - v2_.y));
  }

  rectangle_t Triangle::getFrameRect() const
  {
    double minX = std::min({v1_.x, v2_.x, v3_.x});
    double maxX = std::max({v1_.x, v2_.x, v3_.x});
    double minY = std::min({v1_.y, v2_.y, v3_.y});
    double maxY = std::max({v1_.y, v2_.y, v3_.y});

    return { maxX - minX, maxY - minY, getCentroid() };
  }

  point_t Triangle::getCentroid() const
  {
    return { (v1_.x + v2_.x + v3_.x) / 3.0, (v1_.y + v2_.y + v3_.y) / 3.0 };
  }

  void Triangle::move(const point_t& point)
  {
    point_t centroid = getCentroid();
    double dx = point.x - centroid.x;
    double dy = point.y - centroid.y;
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
    if (k <= 0)
    {
      throw std::invalid_argument("Scaling factor must be positive");
    }

    point_t centroid = getCentroid();

    v1_.x = centroid.x + (v1_.x - centroid.x) * k;
    v1_.y = centroid.y + (v1_.y - centroid.y) * k;
    v2_.x = centroid.x + (v2_.x - centroid.x) * k;
    v2_.y = centroid.y + (v2_.y - centroid.y) * k;
    v3_.x = centroid.x + (v3_.x - centroid.x) * k;
    v3_.y = centroid.y + (v3_.y - centroid.y) * k;
  }
}
