#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t first, point_t second, point_t third);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t Z) override;
    void move(double dx, double dy) override;
    void scale(double V) override;

  private:
    point_t first_;
    point_t second_;
    point_t third_;
  };
}

#endif
