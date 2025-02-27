#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include <cstddef>
#include "shape.hpp"
namespace kiselev
{
  class Complexquad final: public Shape
  {
  public:
    Complexquad(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    Shape* clone() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    const size_t size_;
    point_t arr_[4];
  };
}
#endif
