#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
namespace gavrilova {
  class Polygon : public Shape {
  public:
    Polygon(point_t A, point_t B, point_t C);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double difX, double difY) override;
    void scale(double k) override;
  private:
    size_t size_;
    point_t * verteces_;
    center_;
  };
}
#endif