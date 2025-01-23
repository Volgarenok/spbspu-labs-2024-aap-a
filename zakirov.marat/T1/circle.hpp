#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "ring.hpp"

namespace zakirov
{
  class Circle final: public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) override;
  private:
    static const size_t rings_size_ = 10;
    static const double first_in_radius_ = 0.1;
    Ring * rings_[rings_size_];
  };
}

#endif
