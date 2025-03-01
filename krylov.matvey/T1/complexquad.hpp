#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"
#include "triangle.hpp"

namespace krylov
{
  class Complexquad final: public Shape
  {
  public:
    Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void unsafeScale(double factor) noexcept override;
  private:
    Triangle t1_;
    Triangle t2_;
    Triangle t3_;
    Triangle t4_;
    point_t t1Center_;
    point_t t2Center_;
    point_t t3Center_;
    point_t t4Center_;
    point_t complexquadFrameCenter_;
    point_t findIntersection(const point_t& a, const point_t& b, const point_t& c, const point_t& d) const;
    bool isPointOnSegment(const point_t& point, const point_t& segStart, const point_t& segEnd) const;
  };
  point_t findIntersection(const point_t& a, const point_t& b, const point_t& c, const point_t& d);
  bool isPointOnSegment(const point_t& point, const point_t& segStart, const point_t& segEnd);
}

#endif
