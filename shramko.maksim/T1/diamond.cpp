#include "diamond.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace shramko
{
  Diamond::Diamond(point_t one, point_t two, point_t three)
  {
    center_ = {(one.x + two.x) / 2.0, (one.y + two.y) / 2.0};
    vertices_[0] = one;
    vertices_[1] = two;
    vertices_[2] = three;
    vertices_[3] = {2 * center_.x - three.x, 2 * center_.y - three.y};

    point_t diag1 = {vertices_[1].x - vertices_[0].x, vertices_[1].y - vertices_[0].y};
    point_t diag2 = {vertices_[3].x - vertices_[2].x, vertices_[3].y - vertices_[2].y};
    double dot = diag1.x * diag2.x + diag1.y * diag2.y;

    if (std::abs(dot) > 1e-3)
    {
      throw std::invalid_argument("Diagonals are not perpendicular");
    }
  }

  double Diamond::getArea() const
  {
    double diag1 = distance(vertices_[0], vertices_[1]);
    double diag2 = distance(vertices_[2], vertices_[3]);
    return (diag1 * diag2) / 2.0;
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
    for (auto& vertex : vertices_)
    {
      vertex.x += x;
      vertex.y += y;
    }
    center_.x += x;
    center_.y += y;
  }

  void Diamond::doScale(double k)
  {
    for (auto& vertex : vertices_)
    {
      vertex.x = center_.x + (vertex.x - center_.x) * k;
      vertex.y = center_.y + (vertex.y - center_.y) * k;
    }
  }
}