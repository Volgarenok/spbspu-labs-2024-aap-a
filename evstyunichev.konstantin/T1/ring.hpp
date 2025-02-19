#ifndef RING_HPP
#define RING_HPP
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
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

    private:
      point_t mid_;
      double R_;
      double r_;
  };
}
#endif
