#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(const point_t first, const point_t second, const point_t third);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t scalePoint) override;
    void move(const double dx, const double dy) override;
    void scale(const double scaleCoeff) override;

  private:
    point_t points_[3];
  };
}

#endif
