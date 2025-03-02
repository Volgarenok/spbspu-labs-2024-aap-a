#ifndef RING_HPP
#define RING_HPP
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "regular.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  class Ring final: public Shape
  {
    public:
      Ring(point_t, double, double);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double, double) override;
      void move(point_t) override;
      void scale(double) override;
      Shape * clone() const override;

    private:
      Regular interior_;
      Regular external_;
  };
}
#endif
