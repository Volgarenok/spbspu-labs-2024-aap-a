#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Concave final: public Shape
  {
  public:
    Concave(const point_t first, const point_t second, const point_t third, const point_t last);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t Z) override;
    void move(const double dx, const double dy) override;
    void scale(const double V) override;

  private:
    point_t first_;
    point_t second_;
    point_t third_;
    point_t last_;
  };
}

#endif
