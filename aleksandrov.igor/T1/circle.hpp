#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <cstddef>

namespace aleksandrov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t& center, const double r);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& centerPoint) override;
    void move(const double dx, const double dy) override;
    void scale(const size_t k) override;
  private:
    point_t center_;
    double r_;
  };
}

#endif

