#ifndef REGULAR_HPP
#define RECTANGLE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"
namespace alymova
{
  struct Regular final: public Shape
  {
    Regular() = default;
    Regular(const point_t& pos, const point_t& top, const point_t& other);
    Regular(const Regular& other);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double shift_x, double shift_y) noexcept override;
    void move(const point_t& point) noexcept override;
    void unsafeScale(double ratio) noexcept override;
    Shape* clone() const override;
  private:
    point_t pos_, top_, other_;

    size_t getCntSides() const noexcept;
  };
}
#endif
