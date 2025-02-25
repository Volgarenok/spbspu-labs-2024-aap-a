#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
#include <stdexcept>

namespace dirti
{
  struct Square final: public Shape
  {
  public:
    Square(const point_t left_low, const double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double koef) override;
  private:
    point_t left_low_;
    double length_;
  };
}

#endif