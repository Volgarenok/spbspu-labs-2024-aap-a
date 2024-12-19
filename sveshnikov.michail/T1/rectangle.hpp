#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sveshnikov
{
  class Rectangle : public Shape
  {
  private:
    point_t low_left_;
    point_t up_right_;

  public:
    Rectangle(point_t low_left, point_t up_right);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(point_t p) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double k) override;
  };
}

#endif
