#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace alymova
{
  struct Rectangle final: public Shape
  {
  public:
    Rectangle(point_t p1, point_t p2);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(double shift_x, double shift_y) noexcept override;
    void move(point_t point) noexcept override;
    void unsafeScale(double ratio) noexcept override;
    Shape* clone() const override;
  private:
    point_t low_left_, upp_right_;
    rectangle_t frame_rect_;
  };
}
#endif
