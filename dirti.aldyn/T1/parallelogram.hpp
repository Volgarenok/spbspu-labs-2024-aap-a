#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"

namespace dirti
{
  struct Parallelogram final : public Shape
  {
  public:
    Parallelogram(const point_t p1, const point_t p2, const point_t p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scaleUnsafe(double koef) override;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}

#endif
