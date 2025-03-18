#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "parallelogram.hpp"

namespace dirti
{
  struct Rectangle final: public Shape
  {
  public:
    Rectangle(point_t left_low, point_t right_high);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scaleUnsafe(double koef) override;
  private:
    Parallelogram parallelogram;
  };
}

#endif
