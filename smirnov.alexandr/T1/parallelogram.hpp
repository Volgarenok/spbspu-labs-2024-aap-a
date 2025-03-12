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
    void unsafeScale(double k) noexcept override;
  private:
    point_t vertex1_;
    point_t vertex2_;
    point_t vertex3_;
    point_t vertex4_;
    bool arePointsUnique(const point_t & p1, const point_t & p2, const point_t & p3);
  };
}
#endif
