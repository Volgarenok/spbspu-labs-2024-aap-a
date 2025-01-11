#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include "regular.hpp"
namespace alymova
{
  struct Circle final: public Shape
  {
  public:
    Circle(point_t pos, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double shift_x, double shift_y) override;
    void move(point_t point) override;
    Shape* clone() const override;
  protected:
    point_t pos_;
    double radius_;
    Regular regular_;
    void unsafeScale(double ratio) override;
  };
}
#endif
