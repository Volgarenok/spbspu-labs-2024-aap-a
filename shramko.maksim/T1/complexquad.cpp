#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>

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

    bool has_positive = false;
    bool has_negative = false;

    if (c1 > 1e-6) has_positive = true;
    if (c1 < -1e-6) has_negative = true;
    if (c2 > 1e-6) has_positive = true;
    if (c2 < -1e-6) has_negative = true;
    if (c3 > 1e-6) has_positive = true;
    if (c3 < -1e-6) has_negative = true;
    if (c4 > 1e-6) has_positive = true;
    if (c4 < -1e-6) has_negative = true;

    return !(has_positive && has_negative);
  }

  Complexquad::Complexquad(point_t a, point_t b, point_t c, point_t d):
    t1_(a, b, c),
    t2_(a, c, d)
  {
    points_[0] = a;
    points_[1] = b;
    points_[2] = c;
    points_[3] = d;

    if (!isConvex())
    {
      throw std::invalid_argument("Complexquad is not convex");
    }

    center_.x = (a.x + b.x + c.x + d.x) / 4.0;
    center_.y = (a.y + b.y + c.y + d.y) / 4.0;
  }

  double Complexquad::getArea() const
  {
    return t1_.getArea() + t2_.getArea();
  }

  rectangle_t Complexquad::getFrameRect() const
  {
    return calculateFrameRect(points_, 4);
  }

  void Complexquad::move(double x, double y)
  {
    movePoints(points_, 4, x, y);
    t1_.move(x, y);
    t2_.move(x, y);
  }

  void Complexquad::doScale(double k)
  {
    scalePoints(points_, 4, k, center_);
    try
    {
      t1_ = Triangle(points_[0], points_[1], points_[2]);
      t2_ = Triangle(points_[0], points_[2], points_[3]);
    }
    catch (...)
    {
      throw;
    }
    center_.x = (points_[0].x + points_[1].x + points_[2].x + points_[3].x) / 4.0;
    center_.y = (points_[0].y + points_[1].y + points_[2].y + points_[3].y) / 4.0;
  }
}
