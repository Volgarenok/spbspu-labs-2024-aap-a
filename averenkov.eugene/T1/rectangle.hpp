#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace averenkov
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t& a_, const point_t& c_);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scaleNonChecked(double factor) override;
    void move(const point_t& s) override;
    void move(double dx, double dy) override;
  private:
    point_t a_;
    point_t c_;
  };
}

#endif
