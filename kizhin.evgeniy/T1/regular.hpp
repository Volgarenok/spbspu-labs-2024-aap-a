#ifndef KIZHIN_T1_REGULAR_HPP
#define KIZHIN_T1_REGULAR_HPP

#include "polygon.hpp"

namespace kizhin {
  class Regular final: public Shape
  {
  public:
    Regular(const point_t&, const point_t&, const point_t&);

    rectangle_t getFrameRect() const override;
    double getArea() const override;
    Shape* clone() const override;

    void move(double, double) override;
    void move(const point_t&) override;
    void unsafeScale(double) override;

  private:
    Polygon polygon_;
  };
}

#endif

