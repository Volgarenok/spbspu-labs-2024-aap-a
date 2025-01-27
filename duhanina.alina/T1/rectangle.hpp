#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace duhanina
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t& lt, const point_t& rt);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) noexcept override;
    point_t getCenter() const override;

  private:
    point_t lt_;
    point_t rt_;
  };
}

#endif
