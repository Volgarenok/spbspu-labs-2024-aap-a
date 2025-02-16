#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace zakirov
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t & bottom_left_, const point_t & top_right_);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) noexcept override;
    Shape * clone() const override;
  private:
    point_t bottom_left_;
    point_t top_right_;
  };
}

#endif
