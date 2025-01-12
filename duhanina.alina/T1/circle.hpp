#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cstddef>
#include "shape.hpp"

namespace duhanina
{
  class Circle final: public Shape
  {
  public:
    Circle(const point_t& pos, double radius, size_t count = 9);
    ~Circle();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    size_t count_;
    Shape** ellipses_;
  };
}

#endif
