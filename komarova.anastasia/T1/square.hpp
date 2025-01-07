#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace komarova
{
  struct Square : public Shape
  {
  public:
    Square(point_t low_left, double len);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double coef) override;
  private:
    point_t low_left_;
    double len_;
  };
}

#endif
