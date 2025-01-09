#ifndef REGULAR_HPP
#define REGULAR_HPP

#include <cstddef>
#include "shape.hpp"

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
    Shape* clone() const override;
    void doUnsafeScale(double multiplier) override;
  private:
    point_t first_point_;
    point_t second_point_;
    point_t third_point_;
    double getDist(const point_t& point1, const point_t& point2) const;
    size_t getSideAmount() const;
    bool isEqualPoints(const point_t& point1, const point_t& point2) const;
    void scaleFromFirstPoint(double multiplier, point_t& scale_point);
  };
}

#endif
