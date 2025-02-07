#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace krylov
{
  class Complexquad final : public Shape
  {
  public:
    Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    bool isPointOnSegment(const point_t& point, const point_t& segStart, const point_t& segEnd) const;
  private:
    point_t a_;
    point_t b_;
    point_t c_;
    point_t d_;
    point_t findIntersection(const point_t& a, const point_t& b, const point_t& c, const point_t& d) const;
  };
}

#endif
