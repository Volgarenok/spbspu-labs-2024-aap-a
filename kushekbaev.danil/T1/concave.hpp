#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Concave : public Shape
  {
  public:
    Concave(point_t first, point_t second, point_t third, point_t final);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t Z) override;
    void move(double dx, double dy) override;
    void scale(double V) override;

  private:
    point_t first_;
    point_t second_;
    point_t third_;
    point_t final_;
  };
}

#endif
