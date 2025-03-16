#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "triangle.hpp"

namespace shramko
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t one, point_t two, point_t three);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    Triangle triangle_;
  };
}

#endif
