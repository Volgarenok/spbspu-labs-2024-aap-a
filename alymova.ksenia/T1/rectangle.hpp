#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace alymova
{
  struct Rectangle: public Shape
  {
  public:
    Rectangle(point_t p1, point_t p2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double shift_x, double shift_y) override;
    void move(point_t point) override;
    void scale(double ratio) override;
    Shape* clone() const override;
  private:
    point_t low_left_, upp_right_;
    double width_, height_;
    point_t pos_;
    rectangle_t frame_rect_;
  };
}
#endif
