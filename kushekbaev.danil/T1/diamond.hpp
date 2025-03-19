#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t mid, point_t modX, point_t modY);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t scalePoint) override;
    void move(double dx, double dy) override;
    Shape* clone() const noexcept override;
    virtual void doUnsafeScale(double scaleCoeff) override;

  private:
    Parallelogram parallelogram_;
  };
}

#endif
