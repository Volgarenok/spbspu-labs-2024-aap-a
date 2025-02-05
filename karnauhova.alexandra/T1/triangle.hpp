#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace karnauhova
{
  class Triangle final: public Shape
  {
  public:
    Triangle(const point_t& x1, const point_t& x2, const point_t& x3);
    void move(double x, double y) override;
    void move(const point_t& t) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scale(double k) override;
    Shape* clone() const;
  private:
    point_t x1_;
    point_t x2_;
    point_t x3_;
  };
}
#endif
