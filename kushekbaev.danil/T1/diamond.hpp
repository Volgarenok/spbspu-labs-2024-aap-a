#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  class Diamond final: public Parallelogram
  {
  public:
    Diamond(const point_t middle, const point_t diffX, const point_t diffY);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t Z) override;
    void move(const double dx, const double dy) override;
    void scale(const double V) override;

  private:
    point_t middle_;
    point_t diffX_;
    point_t diffY_;
  };
}

#endif
