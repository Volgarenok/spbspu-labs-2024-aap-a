#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
namespace shramko
{
  bool Complexquad::isConvex() const
  {
    auto cross = [](const point_t& a, const point_t& b, const point_t& c)
    {
      return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
    };
    double c1 = cross(points_[0], points_[1], points_[2]);
    double c2 = cross(points_[1], points_[2], points_[3]);
    double c3 = cross(points_[2], points_[3], points_[0]);
    double c4 = cross(points_[3], points_[0], points_[1]);

    return (c1 >= -1e-6 && c2 >= -1e-6 && c3 >= -1e-6 && c4 >= -1e-6) ||
           (c1 <= 1e-6 && c2 <= 1e-6 && c3 <= 1e-6 && c4 <= 1e-6);
  }

  Complexquad::Complexquad(point_t a, point_t b, point_t c, point_t d):
    t1_(a, b, c),
    t2_(c, d, a),
    t3_(b, c, d),
    t4_(a, d, b)
  {
    points_[0] = a;
    points_[1] = b;
    points_[2] = c;
    points_[3] = d;

    center_.x = (a.x + b.x + c.x + d.x) / 4.0;
    center_.y = (a.y + b.y + c.y + d.y) / 4.0;
  }

  double Complexquad::getArea() const
  {
    return t1_.getArea() + t2_.getArea() + t3_.getArea() + t4_.getArea();
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
    t3_.move(x, y);
    t4_.move(x, y);

    center_.x += x;
    center_.y += y;
  }
  void Complexquad::doScale(double k)
  {
    const point_t center = getFrameRect().pos;

    point_t new_points[4];
    std::copy(std::begin(points_), std::end(points_), std::begin(new_points));

    try
    {
      for (auto& point : new_points)
      {
        point.x = center.x + (point.x - center.x) * k;
        point.y = center.y + (point.y - center.y) * k;
      }

      Triangle new_t1(new_points[0], new_points[1], new_points[2]);
      Triangle new_t2(new_points[2], new_points[3], new_points[0]);
      Triangle new_t3(new_points[1], new_points[2], new_points[3]);
      Triangle new_t4(new_points[0], new_points[3], new_points[1]);

      t1_ = new_t1;
      t2_ = new_t2;
      t3_ = new_t3;
      t4_ = new_t4;

      std::copy(std::begin(new_points), std::end(new_points), std::begin(points_));

      center_.x = (new_points[0].x + new_points[1].x + new_points[2].x + new_points[3].x) / 4.0;
      center_.y = (new_points[0].y + new_points[1].y + new_points[2].y + new_points[3].y) / 4.0;
    }
    catch (...)
    {
      throw;
    }
  }
}
