#ifndef REGULAR_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace alymova
{
  struct Regular: public Shape
  {
  public:
    Regular(point_t pos, point_t top, point_t other);
    double getArea() const override;
    size_t getCntSides() const;
    rectangle_t getFrameRect() const override;
    rectangle_t setFrameRect();
    void move(double shift_x, double shift_y) override;
    void move(point_t point) override;
    void scale(double ratio) override;
  private:
    point_t pos_, top_, other_;
    double radius_big_, radius_small_, other_side_;
    size_t sides_cnt_;
    rectangle_t frame_rect_;
  };
}
#endif
