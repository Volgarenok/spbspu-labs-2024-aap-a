#include "diamond.hpp"
#include <stdexcept>
#include <cmath>

namespace shramko
{
  point_t Diamond::midpoint(const point_t& a, const point_t& b) const
  {
    return {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
  }

  bool Diamond::areDiagonalsPerpendicular() const
  {
    point_t diag1 = {vertices_[1].x - vertices_[0].x, vertices_[1].y - vertices_[0].y};
    point_t diag2 = {vertices_[3].x - vertices_[2].x, vertices_[3].y - vertices_[2].y};
    double dot = diag1.x * diag2.x + diag1.y * diag2.y;
    return std::abs(dot) < 1e-6;
  }

  Diamond::Diamond(point_t one, point_t two, point_t three)
  {
    center_ = midpoint(one, two);
    vertices_[0] = one;
    vertices_[1] = two;
    vertices_[2] = three;
    vertices_[3] = {2 * center_.x - three.x, 2 * center_.y - three.y};

    if (!areDiagonalsPerpendicular())
    {
      throw std::invalid_argument("Diagonals are not perpendicular");
    }

    triangles_ = new Triangle*[TRIANGLE_COUNT];
    try
    {
      point_t mid01 = midpoint(vertices_[0], vertices_[1]);
      point_t mid12 = midpoint(vertices_[1], vertices_[2]);
      point_t mid23 = midpoint(vertices_[2], vertices_[3]);
      point_t mid30 = midpoint(vertices_[3], vertices_[0]);

      triangles_[0] = new Triangle(vertices_[0], mid01, center_);
      triangles_[1] = new Triangle(mid01, vertices_[1], center_);
      triangles_[2] = new Triangle(vertices_[1], mid12, center_);
      triangles_[3] = new Triangle(mid12, vertices_[2], center_);
      triangles_[4] = new Triangle(vertices_[2], mid23, center_);
      triangles_[5] = new Triangle(mid23, vertices_[3], center_);
      triangles_[6] = new Triangle(vertices_[3], mid30, center_);
      triangles_[7] = new Triangle(mid30, vertices_[0], center_);
    }
    catch (...)
    {
      for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
      {
        delete triangles_[i];
      }
      delete[] triangles_;
      throw;
    }
  }

  Diamond::~Diamond()
  {
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i) delete triangles_[i];
    delete[] triangles_;
  }

  double Diamond::getArea() const
  {
    double area = 0.0;
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
    {
      area += triangles_[i]->getArea();
    }
    return area;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    double x_min = vertices_[0].x;
    double x_max = vertices_[0].x;
    double y_min = vertices_[0].y;
    double y_max = vertices_[0].y;

    for (const auto& vertex : vertices_)
    {
      x_min = std::min(x_min, vertex.x);
      x_max = std::max(x_max, vertex.x);
      y_min = std::min(y_min, vertex.y);
      y_max = std::max(y_max, vertex.y);
    }

    return {x_max - x_min, y_max - y_min, {(x_min + x_max)/2, (y_min + y_max)/2}};
  }

  void Diamond::move(double x, double y)
  {
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
    {
      triangles_[i]->move(x, y);
    }
    center_.x += x;
    center_.y += y;
    for (auto& vertex : vertices_)
    {
      vertex.x += x;
      vertex.y += y;
    }
  }

  void Diamond::doScale(double k)
  {
    for (auto& vertex: vertices_)
    {
      vertex.x = center_.x + (vertex.x - center_.x) * k;
      vertex.y = center_.y + (vertex.y - center_.y) * k;
    }

    point_t mid01 = midpoint(vertices_[0], vertices_[1]);
    point_t mid12 = midpoint(vertices_[1], vertices_[2]);
    point_t mid23 = midpoint(vertices_[2], vertices_[3]);
    point_t mid30 = midpoint(vertices_[3], vertices_[0]);

    *triangles_[0] = Triangle(vertices_[0], mid01, center_);
    *triangles_[1] = Triangle(mid01, vertices_[1], center_);
    *triangles_[2] = Triangle(vertices_[1], mid12, center_);
    *triangles_[3] = Triangle(mid12, vertices_[2], center_);
    *triangles_[4] = Triangle(vertices_[2], mid23, center_);
    *triangles_[5] = Triangle(mid23, vertices_[3], center_);
    *triangles_[6] = Triangle(vertices_[3], mid30, center_);
    *triangles_[7] = Triangle(mid30, vertices_[0], center_);
  }
}
