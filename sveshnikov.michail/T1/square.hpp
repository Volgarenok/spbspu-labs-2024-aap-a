#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"

namespace sveshnikov
{
  class Square final: public Shape
  {
  public:
    Square(point_t low_left_, double side_);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t p) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) override;
    Shape *clone() const override;

  private:
    point_t low_left_;
    double side_;
  };
}

#endif
