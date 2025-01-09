#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace finaev
{
  class Concave final: public Shape
  {
  public:
    Concave(point_t f, point_t s, point_t t, point_t i);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(double k) override;
  private:
    point_t first;
    point_t second;
    point_t third;
    point_t internal;
  };
  double len(point_t a, point_t b);
  bool operator ==(const finaev::point_t a, const finaev::point_t b);
}

#endif
