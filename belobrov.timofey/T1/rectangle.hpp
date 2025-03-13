#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace belobrov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& lowerLeft, const point_t& upperRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
  private:
    point_t lowerLeft_;
    point_t upperRight_;
  };
}

#endif
