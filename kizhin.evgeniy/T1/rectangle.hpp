#ifndef KIZHIN_T1_RECTANGLE_HPP
#define KIZHIN_T1_RECTANGLE_HPP

#include "shape.hpp"

namespace kizhin {
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t&, const point_t&);

    rectangle_t getFrameRect() const override;
    double getArea() const override;
    Shape* clone() const override;

    void move(const point_t&) override;
    void move(double, double) override;
    void unsafeScale(double) override;

  private:
    rectangle_t data_;

    point_t computePosition(const point_t&, const point_t&);
  };
}

#endif

