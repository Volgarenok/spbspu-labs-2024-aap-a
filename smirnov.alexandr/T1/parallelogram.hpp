#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"

namespace smirnov
{
  class Parallelogram final: public Shape
  {
  public:
    Parallelogram(point_t p1, point_t p2, point_t p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t vertex1;
    point_t vertex2;
    point_t vertex3;
    point_t vertex4;
  };
}
#endif
