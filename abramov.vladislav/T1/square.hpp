#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"

namespace abramov
{
  struct Square final: Shape
  {
    Square(point_t p, double len);
    Square(Rectangle rect);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Square *clone() const override;
    Rectangle getRect() const;
  private:
    Rectangle rect_;
  };
}
#endif

