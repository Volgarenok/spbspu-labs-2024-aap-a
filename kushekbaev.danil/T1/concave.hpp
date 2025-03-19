#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  class Concave final: public Shape
  {
  public:
    Concave(point_t first, point_t second, point_t third, point_t last);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t scalePoint) override;
    void move(double dx, double dy) override;
    Shape* clone() const override;
    virtual void doUnsafeScale(double scaleCoeff) override;

  private:
    point_t points_[4];
    Parallelogram mainpar_;
    Parallelogram concpar_;
  };
}

#endif
