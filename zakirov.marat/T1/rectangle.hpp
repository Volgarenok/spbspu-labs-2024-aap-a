#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace zakirov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t bottom_left_, point_t top_right_);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) override;
  private:
    point_t bottom_left_;
    point_t top_right_;
  };
}

#endif
