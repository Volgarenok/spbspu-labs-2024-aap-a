#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "shape.hpp"
#include <stddef.h>

namespace mozhegova
{
  class Polygon : public Shape
  {
  public:
    Polygon(size_t n, point_t * arr);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ~Polygon();
  private:
    size_t count = 0;
    point_t * points = nullptr;
  };
}

#endif
