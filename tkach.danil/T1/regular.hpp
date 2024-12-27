#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"
#include <cstddef>

namespace tkach
{
  class Regular final: public Shape
  {
  public:
    Regular(const point_t& first_point, const point_t& second_point, const point_t& third_point);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double add_to_x, double add_to_y) override;
    void move(const point_t& point_to_move) override;
    void scaleShape(double multiplier) override;
  private:
    point_t first_point_;
    point_t second_point_;
    point_t third_point_;
    double first_side_out_r_;
    double second_side_in_r_;
    double third_side_;
    size_t amount_of_sides_;
    double getDist(const point_t& point1, const point_t& point2) const;
    size_t getSideAmount() const;
    bool isEqualPoints(const point_t& point1, const point_t& point2) const;
  };
}

#endif
