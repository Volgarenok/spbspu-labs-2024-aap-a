#ifndef REGULAR_HPP
#define REGULAR_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  class Regular final: public Shape
  {
    public:
      Regular(point_t, point_t, point_t);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double, double) override;
      void move(point_t) override;
      void scale(double k) override;
      double getSmall() const;
      double getBig() const;

    private:
      point_t O_;
      double alpha_;
      double a_;
  };
}
#endif
