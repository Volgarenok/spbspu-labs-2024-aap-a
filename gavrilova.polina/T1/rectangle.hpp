#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Rectangle : public Shape {
  public:
    Rectangle(point_t pBottomLeft, point_t pTopRigh);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double difX, double difY) override;
    void scale(double k) override;
  private:
    point_t pBottomLeft_;
    point_t pTopRight_;
  };
}
#endif