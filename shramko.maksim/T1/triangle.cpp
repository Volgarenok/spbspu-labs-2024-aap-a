#include "triangle.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

namespace shramko
{
  Triangle::Triangle(point_t one, point_t two, point_t three):
    one_(one),
    two_(two),
    three_(three)
  {
    double A = distance(one_, two_);
    double B = distance(two_, three_);
    double C = distance(one_, three_);

    if (A + B <= C || B + C <= A || A + C <= B)
    {
      throw std::invalid_argument("Triangle size err\n");
    }
    if (getArea() < 1e-6)
    {
      throw std::invalid_argument("Triangle size err\n");
    }

    center_.x = (one_.x + two_.x + three_.x) / 3.0;
    center_.y = (one_.y + two_.y + three_.y) / 3.0;
  }

  double Triangle::getArea() const
  {
    return std::abs((one_.x * (two_.y - three_.y) + two_.x * (three_.y - one_.y) + three_.x * (one_.y - two_.y)) / 2.0);
  }

  rectangle_t Triangle::getFrameRect() const
  {
    point_t points[3] = {one_, two_, three_};
    return calculateFrameRect(points, 3);
  }

  void Triangle::move(double x, double y)
  {
    point_t points[3] = {one_, two_, three_};
    movePoints(points, 3, x, y);
    one_ = points[0];
    two_ = points[1];
    three_ = points[2];
  }

  void Triangle::doScale(double k)
  {
    point_t points[3] = {one_, two_, three_};
    scalePoints(points, 3, k, center_);
    one_ = points[0];
    two_ = points[1];
    three_ = points[2];
    center_.x = (one_.x + two_.x + three_.x) / 3.0;
    center_.y = (one_.y + two_.y + three_.y) / 3.0;
  }
}
