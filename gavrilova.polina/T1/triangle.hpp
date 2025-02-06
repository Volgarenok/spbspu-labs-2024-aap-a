#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Triangle final: public Shape {
  public:
    Triangle(const point_t& a, const point_t& b, const point_t& c);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& p) override;
    void move(double difX, double difY) override;
    Shape* clone() const;
    void scaleWithoutCheck(double k) noexcept override;
  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}
#endif
