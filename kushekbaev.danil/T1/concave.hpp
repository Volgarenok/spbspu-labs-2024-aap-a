#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  class Concave : public Shape
  {
  public:
    Concave(const point_t first, const point_t second, const point_t third, const point_t final);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t Z) override;
    void move(const double dx, const double dy) override;
    void scale(const double V) override;

  private:
    point_t first_;
    point_t second_;
    point_t third_;
    point_t final_;
    Parallelogram parallelogram1_;
    Parallelogram parallelogram2_;
  };
}

#endif
