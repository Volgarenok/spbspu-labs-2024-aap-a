#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>

namespace shramko
{
  Complexquad::Complexquad(point_t p1, point_t p2, point_t p3, point_t p4)
  {
    points_[0] = p1;
    points_[1] = p2;
    points_[2] = p3;
    points_[3] = p4;

    validateConvex();

    center_.x = (p1.x + p2.x + p3.x + p4.x) / 4;
    center_.y = (p1.y + p2.y + p3.y + p4.y) / 4;
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
