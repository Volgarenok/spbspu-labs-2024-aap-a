#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "ellipse.hpp"
#include <cstddef>

namespace duhanina
{
  class Circle final: public Shape
  {
  public:
    static constexpr size_t NUM_PARTS = 9;
    Circle(const point_t& center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    Ellipse ellipses_[NUM_PARTS];
  };
}

#endif
