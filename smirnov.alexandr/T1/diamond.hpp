#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "parallelogram.hpp"

namespace smirnov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t p1, point_t p2, point_t p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) noexcept override;
  private:
    Parallelogram parallelogram_;
  };
}
#endif
