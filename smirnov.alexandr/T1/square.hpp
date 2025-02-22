#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"

namespace smirnov
{
  class Square final: public Shape
  {
  public:
    Square(double x, double y, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) noexcept override;
  private:
    point_t lowerLeft_;
    double sideLength_;
  };
}
#endif
