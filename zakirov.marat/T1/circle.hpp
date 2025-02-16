#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cstddef>
#include "shape.hpp"
#include "ring.hpp"

namespace zakirov
{
  class Circle final: public Shape
  {
  public:
    Circle(const point_t & center, double radius);
    ~Circle();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) noexcept override;
    Shape * clone() const override;
  private:
    static constexpr size_t rings_size_ = 100;
    static constexpr double first_in_radius_ = 0.01;
    Ring * rings_[rings_size_];
  };
}

#endif
