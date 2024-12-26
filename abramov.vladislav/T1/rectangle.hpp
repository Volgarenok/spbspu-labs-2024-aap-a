#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace abramov
{
  struct Rectangle: Shape
  {
    Rectangle(point_t p1, point_t p2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t pLeftLower_;
    point_t pRightUpper_;
  };

  friend point_t Rectangle::getpLeftLower(const Rectangle &rect);
  friend point_t Rectangle::getpRightUpper(const Rectangle &rect);
}
#endif
