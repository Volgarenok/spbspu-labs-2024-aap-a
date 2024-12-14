#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"

namespace hismatova
{
  struct concave: public shape
  {
    concave(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
    void move(point_t point) override;
    void scale(double index) override;
private:
  point_t p1_, p2_, p3_, p4_;
};
}

#endif
