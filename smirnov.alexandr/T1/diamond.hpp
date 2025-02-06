#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "parallelogram.hpp"

namespace smirnov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t p1, point_t p2, point_t p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t vertex1;
    point_t vertex2;
    point_t vertex3;
    /*point_t center;*/
    Parallelogram parallelogram;
    /*point_t rotatePoint(const point_t& point, const point_t& center, double angle_rad) const;
    point_t computeCenter(const point_t& p1, const point_t& p2, const point_t& p3) const;*/
  };
}
#endif
