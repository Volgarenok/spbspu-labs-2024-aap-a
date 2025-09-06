#include "diamond.hpp"
#include <stdexcept>
#include <cmath>

namespace shramko
{
  Diamond::Diamond(point_t one, point_t two, point_t three):
    vertices_({{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}}}),
    triangles_(nullptr)
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

    center_.x = two.x;
    center_.y = two.y;

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
    return calculateFrameRect(vertices_.data(), vertices_.size());
  }

  void Diamond::move(double x, double y)
  {
    movePoints(vertices_.data(), vertices_.size(), x, y);
    for (size_t i = 0; i < TRIANGLE_COUNT; ++i)
    {
      triangles_[i]->move(x, y);
    }
  }

  void Diamond::doScale(double k)
  {
    std::array<point_t, 4> old_vertices = vertices_;
    try
    {
      scalePoints(vertices_.data(), vertices_.size(), k, center_);
      *triangles_[0] = Triangle(center_, vertices_[0], vertices_[1]);
      *triangles_[1] = Triangle(center_, vertices_[1], vertices_[2]);
      *triangles_[2] = Triangle(center_, vertices_[2], vertices_[3]);
      *triangles_[3] = Triangle(center_, vertices_[3], vertices_[0]);
    }
    catch (...)
    {
      vertices_ = old_vertices;
      throw;
    }
  }
}
