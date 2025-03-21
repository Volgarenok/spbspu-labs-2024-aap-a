#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace belobrov
{
  class Triangle : public Shape
  {
  public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    double getArea() const override;
    point_t getCentroid() const;
    rectangle_t getFrameRect() const override;
    void move(const point_t& p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t v1_, v2_, v3_;
  };
}

#endif
