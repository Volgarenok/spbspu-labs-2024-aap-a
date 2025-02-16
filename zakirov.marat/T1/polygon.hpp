#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace zakirov
{
  class Polygon final: public Shape
  {
  public:
    Polygon(size_t size, point_t * points);
    ~Polygon();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &  target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) noexcept override;
    Shape * clone() const override;
  private:
    size_t size_;
    point_t * points_;
  };
}

#endif
