#include "diamond.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace shramko
{
  Diamond::Diamond(point_t one, point_t two, point_t three): center_(two)
  {
    vertices_[0] = one;
    vertices_[1] = three;
    vertices_[2] = {2 * two.x - one.x, 2 * two.y - one.y};
    vertices_[3] = {2 * two.x - three.x, 2 * two.y - three.y};

    point_t diag1 = {vertices_[2].x - one.x, vertices_[2].y - one.y};
    point_t diag2 = {vertices_[3].x - three.x, vertices_[3].y - three.y};
    double dot = diag1.x * diag2.x + diag1.y * diag2.y;

    if (std::abs(dot) > 1e-3)
    {
      throw std::invalid_argument("Diagonals are not perpendicular");
    }

    triangles_ = new Triangle*[TRIANGLE_COUNT]();
    try
    {
      triangles_[0] = new Triangle(center_, vertices_[0], vertices_[1]);
      triangles_[1] = new Triangle(center_, vertices_[1], vertices_[2]);
      triangles_[2] = new Triangle(center_, vertices_[2], vertices_[3]);
      triangles_[3] = new Triangle(center_, vertices_[3], vertices_[0]);
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
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i) 
    {
      delete triangles_[i];
    }
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
    for (auto& vertex : vertices_)
    {
      vertex.x = center_.x + (vertex.x - center_.x) * k;
      vertex.y = center_.y + (vertex.y - center_.y) * k;
    }

    *triangles_[0] = Triangle(center_, vertices_[0], vertices_[1]);
    *triangles_[1] = Triangle(center_, vertices_[1], vertices_[2]);
    *triangles_[2] = Triangle(center_, vertices_[2], vertices_[3]);
    *triangles_[3] = Triangle(center_, vertices_[3], vertices_[0]);
  }
}
