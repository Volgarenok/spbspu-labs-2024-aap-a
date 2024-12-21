#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace krylov
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t& a, const point_t& b, const point_t& c);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
  private:
    point_t a_, b_, c_;
  };
}

#endif
