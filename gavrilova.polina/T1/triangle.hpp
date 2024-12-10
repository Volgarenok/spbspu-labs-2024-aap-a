#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Triangle : public Shape {
  public:
    Triangle(point_t A, point_t B, point_t C);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double difX, double difY) override;
    void scale(double k) override;
    point_t getCenter();
  private:
    point_t A_;
    point_t B_;
    point_t C_;
  };
  bool isTriangle(point_t A, point_t B, point_t C);
  double getDistance(point_t A, point_t B);
}
#endif
