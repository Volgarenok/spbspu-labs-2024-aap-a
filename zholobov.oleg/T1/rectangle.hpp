#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace zholobov {

  class Rectangle : public Shape {
  public:
    Rectangle();
    Rectangle(const point_t& a, const point_t& c);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    rectangle_t rect_;
  };

}

#endif
