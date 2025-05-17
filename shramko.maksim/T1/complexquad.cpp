#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>

namespace shramko
{
  Complexquad::Complexquad(point_t one, point_t two, point_t three, point_t four)
  {
    if (!isConvex(one, two, three, four))
    {
      throw std::invalid_argument("Points don't form convex quadrilateral");
    }

    points_[0] = one;
    points_[1] = two;
    points_[2] = three;
    points_[3] = four;

    validateConvex();

    center_.x = (one.x + two.x + three.x + four.x) / 4;
    center_.y = (one.y + two.y + three.y + four.y) / 4;
  }

  bool Complexquad::isConvex(const point_t& a, const point_t& b, const point_t& c, const point_t& d) const
  {
    auto cross = [](const point_t& p1, const point_t& p2, const point_t& p3)
    {
      return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
    };

    double c1 = cross(a, b, c);
    double c2 = cross(b, c, d);
    double c3 = cross(c, d, a);
    double c4 = cross(d, a, b);

    bool all_non_neg = (c1 >= 0) && (c2 >= 0) && (c3 >= 0) && (c4 >= 0);
    bool all_non_pos = (c1 <= 0) && (c2 <= 0) && (c3 <= 0) && (c4 <= 0);

    return all_non_neg || all_non_pos;
  }

  bool Complexquad::isConvex(const point_t& a, const point_t& b, const point_t& c, const point_t& d) const
  {
    auto orientation = [](const point_t& p1, const point_t& p2, const point_t& p3)
    {
      double val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

      if (std::abs(val) < 1e-6) return 0;
      return (val > 0) ? 1 : 2;
    };

    int o1 = orientation(a, b, c);
    int o2 = orientation(b, c, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(d, a, b);

    if (o1 != o2 && o2 != o3 && o3 != o4 && o1 != o3 && o1 != o4 && o2 != o4)
    {
      return false;
    }

    return true;
  }

  double Complexquad::getArea() const
  {
    Triangle t1(points_[0], points_[1], points_[2]);
    Triangle t2(points_[0], points_[2], points_[3]);
    return t1.getArea() + t2.getArea();
  }

  rectangle_t Complexquad::getFrameRect() const
  {
    double xMin = points_[0].x;
    double xMax = points_[0].x;
    double yMin = points_[0].y;
    double yMax = points_[0].y;

    for (size_t i = 1; i < 4; ++i)
    {
      xMin = std::min(xMin, points_[i].x);
      xMax = std::max(xMax, points_[i].x);
      yMin = std::min(yMin, points_[i].y);
      yMax = std::max(yMax, points_[i].y);
    }

    return {xMax - xMin, yMax - yMin, { (xMin + xMax) / 2, (yMin + yMax) / 2 }};
  }

  void Complexquad::move(double x, double y)
  {
    for (int i = 0; i < 4; ++i)
    {
      points_[i].x += x;
      points_[i].y += y;
    }
    center_.x += x;
    center_.y += y;
  }

  void Complexquad::doScale(double k)
  {
    for (int i = 0; i < 4; ++i)
    {
      points_[i].x = center_.x + (points_[i].x - center_.x) * k;
      points_[i].y = center_.y + (points_[i].y - center_.y) * k;
    }
  }

  void Complexquad::validateConvex() const
  {
    const double cross1 = (points_[1].x - points_[0].x) * (points_[2].y - points_[1].y)
                        - (points_[1].y - points_[0].y) * (points_[2].x - points_[1].x);

    const double cross2 = (points_[2].x - points_[1].x) * (points_[3].y - points_[2].y)
                        - (points_[2].y - points_[1].y) * (points_[3].x - points_[2].x);

    const double cross3 = (points_[3].x - points_[2].x) * (points_[0].y - points_[3].y)
                        - (points_[3].y - points_[2].y) * (points_[0].x - points_[3].x);

    const double cross4 = (points_[0].x - points_[3].x) * (points_[1].y - points_[0].y)
                        - (points_[0].y - points_[3].y) * (points_[1].x - points_[0].x);

    if (!((cross1 >= 0 && cross2 >= 0 && cross3 >= 0 && cross4 >= 0)
       || (cross1 <= 0 && cross2 <= 0 && cross3 <= 0 && cross4 <= 0)))
    {
      throw std::invalid_argument("Points don't form convex quadrilateral");
    }
  }
}
