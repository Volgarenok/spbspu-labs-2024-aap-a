#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace hismatova
{
  struct rectangle : public shape
  {
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
    void move(point_t point) override;
    void scale(double index) override;
    rectangle(double left_x, double left_y, double right_x, double right_y);
  private:
    point_t left_;
    point_t right_;
  };
}

#endif
