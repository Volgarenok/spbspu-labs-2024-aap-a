#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace demehin
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t left_bot, point_t right_top);
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
