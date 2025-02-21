#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <iostream>
#include "base-types.hpp"
#include "regular.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  class Circle: public Shape
  {
    public:
      Circle(point_t, double);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double, double) override;
      void move(point_t) override;
      void scale(double) override;

    private:
      Regular *data;
  };
}
#endif
