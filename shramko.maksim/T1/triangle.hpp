#ifndef TRANGLE_HPP
#define TRANGLE_HPP

#include "shape.hpp"

namespace shramko
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t one, point_t two, point_t three);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t one_;
    point_t two_;
    point_t three_;
  };
}

#endif
