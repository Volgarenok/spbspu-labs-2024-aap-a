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
    void move(const point_t scalePoint) override;
    void move(const double dx, const double dy) override;
    void scale(const double scaleCoeff) override;

  private:
    point_t points_[4] = {first_, second_, third_, last_};
  };
}

#endif
