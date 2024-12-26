#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace abramov
{
  struct Square: Shape
  {
    Square(point_t p, double len);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    point_t getpLeftLower() const;
    double getlen() const;
  private:
    point_t pLeftLower_;
    double len_;
  };
}
#endif

