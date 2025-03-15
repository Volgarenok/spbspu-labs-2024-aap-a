#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t first, point_t second, point_t third);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t scalePoint) override;
    void move(double dx, double dy) override;
    void scale(double scaleCoeff) override;
    Shape* clone() const override;

  private:
    point_t points_[3];
  };
}

#endif
