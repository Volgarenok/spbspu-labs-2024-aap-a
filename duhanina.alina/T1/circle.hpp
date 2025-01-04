#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace duhanina
{
  class Circle final: public Shape
  {
  public:
    Circle(const point_t& center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif
