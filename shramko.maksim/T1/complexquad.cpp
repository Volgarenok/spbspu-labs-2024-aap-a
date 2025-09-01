#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace shramko
{
  namespace
  {
    point_t intersect(const point_t& a, const point_t& b, const point_t& c, const point_t& d)
    {
      double denom = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
      if (std::abs(denom) < 1e-10)
      {
        throw std::invalid_argument("Diagonals are parallel");
      }
      double x = ((a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x)) / denom;
      double y = ((a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x)) / denom;
      return {x, y};
    }
  }

  Complexquad::Complexquad(point_t a, point_t b, point_t c, point_t d):
    t1_(a, b, c),
    t2_(a, c, d)
  {
    points_[0] = a;
    points_[1] = b;
    points_[2] = c;
    points_[3] = d;

    try
    {
      center_ = intersect(a, c, b, d);
    }
    catch (const std::invalid_argument& e)
    {
      throw std::invalid_argument("Complexquad is not valid: " + std::string(e.what()));
    }
  }

  double Complexquad::getArea() const
  {
    return t1_.getArea() + t2_.getArea();
  }

  rectangle_t Complexquad::getFrameRect() const
  {
    double x_min = points_[0].x;
    double x_max = points_[0].x;
    double y_min = points_[0].y;
    double y_max = points_[0].y;

    for (const auto& point : points_)
    {
      x_min = std::min(x_min, point.x);
      x_max = std::max(x_max, point.x);
      y_min = std::min(y_min, point.y);
      y_max = std::max(y_max, point.y);
    }

    return {x_max - x_min, y_max - y_min, {(x_min + x_max)/2, (y_min + y_max)/2}};
  }

  void Complexquad::move(double x, double y)
  {
    for (auto& point : points_)
    {
      point.x += x;
      point.y += y;
    }
    t1_.move(x, y);
    t2_.move(x, y);
    center_.x += x;
    center_.y += y;
  }

  void Complexquad::doScale(double k)
  {
    for (auto& point : points_)
    {
      point.x = center_.x + (point.x - center_.x) * k;
      point.y = center_.y + (point.y - center_.y) * k;
    }

    t1_ = Triangle(points_[0], points_[1], points_[2]);
    t2_ = Triangle(points_[0], points_[2], points_[3]);
  }
}
