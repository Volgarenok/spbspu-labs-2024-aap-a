#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include "regular.hpp"
namespace alymova
{
  struct Circle final: public Shape
  {
    Circle(const point_t& pos, double radius);
    Circle(const Circle& other);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double shift_x, double shift_y) noexcept override;
    void move(const point_t& point) noexcept override;
    void unsafeScale(double ratio) noexcept override;
    Shape* clone() const override;
  private:
    Regular regular_;

    Regular setRegular(const point_t& pos, double radius);
  };
}
#endif
