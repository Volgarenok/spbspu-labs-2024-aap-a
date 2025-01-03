#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>
#include "base-types.hpp"

namespace zakirov
{
  class Polygon : public Shape
  {
  public:
    Polygon(size_t size, point_t * points);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) override;
  private:
    size_t size_;
    point_t * points_;
  };
}

#endif
