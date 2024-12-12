#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace guseynov
{
  class Square : public Shape
  {
  public:
    Square(point_t leftLowP, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t leftLowP_;
    double length_;
  };
}

#endif
