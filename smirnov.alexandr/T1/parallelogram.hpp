#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"

namespace smirnov
{
  class Parallelogram : public Shape
  {
  private:
    point_t vertex1;
    point_t vertex2;
    point_t vertex3;
  public:
    Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}
#endif
