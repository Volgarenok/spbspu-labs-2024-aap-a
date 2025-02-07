#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace averenkov
{
  class Ellipse final: public Shape
  {
  public:
    Ellipse(const point_t& center, double radius_v, double radius_h);
    void scaleNonChecked(double factor) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& s) override;
    void move(double dx, double dy) override;
  private:
    point_t center_;
    double radius_v_;
    double radius_h_;
  };
}

#endif
