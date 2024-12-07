#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>

namespace demehin
{
  class Polygon: public Shape
  {
  public:
    Polygon(size_t vrtx_cnt, const point_t* vertex);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    size_t vrtx_cnt_ = 0;
    point_t vertex_[10000];
  };
}

#endif
