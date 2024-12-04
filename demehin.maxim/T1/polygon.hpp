#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include "base_types.hpp"
#include <cstddef>

namespace demehin
{
  class Polygon: public Shape
  {
  public:
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
    point_t* vertex_[10000] = {};
    size_t vrtx_cnt_ = 0;
  };
}

#endif
