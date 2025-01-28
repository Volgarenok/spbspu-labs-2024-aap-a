#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cstddef>
#include "shape.hpp"

namespace duhanina
{
  class Circle final: public Shape
  {
  public:
    Circle(const point_t& pos, double radius);
    ~Circle();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scaleUnsafe(double k) noexcept override;

  private:
    static constexpr size_t numParts_ = 9;
    Shape** ellipses_;
  };
}

#endif
