#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base_types.hpp"
#include "shape.hpp"

namespace demehin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double lbx, double lby, double rtx, double rty);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t lb_;
    point_t rt_;
  };
}

#endif
