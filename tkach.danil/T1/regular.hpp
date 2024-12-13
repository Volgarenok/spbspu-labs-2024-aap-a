#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"
#include <cstddef>

namespace tkach
{
  class Regular: public Shape
  {
  public:
    Regular(point_t first_point, point_t second_point, point_t third_point);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double add_to_x, double add_to_y) override;
    void move(point_t point_to_move) override;
    void scale(double multiplier) override;
  private:
    point_t first_point_;
    point_t second_point_;
    point_t third_point_;
    double first_side_out_r_;
    double second_side_in_r_;
    double third_side_;
    size_t amount_of_sides_;
    double getDist(point_t point1, point_t point2) const;
    size_t getSideAmount() const;
    bool isEqualPoints(point_t point1, point_t point2) const;
  };
}

#endif
