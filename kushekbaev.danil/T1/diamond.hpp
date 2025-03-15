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
    void scale(double scaleCoeff) override;
    Shape* clone() const noexcept override;

  private:
    Parallelogram parallelogram_;
  };
}

#endif
