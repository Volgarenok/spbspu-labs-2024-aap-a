#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace karnauhova
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t x1, point_t x2, point_t x3): x1_(x1), x2_(x2), x3_(x3)
    {}
    void move(double x, double y) override;
    void move(point_t t) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scale(double k) override;
    ~Triangle(){}
  private:
    point_t x1_;
    point_t x2_;
    point_t x3_;
  };
}
#endif
