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
      Regular(point_t, double, size_t);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double, double) override;
      void move(point_t) override;
      void scale(double k) override;
      double get_r() const;
      double get_R() const;
      point_t getMiddle() const;
      Shape * copy() const override;

    private:
      point_t middle_;
      double alpha_;
      double a_;
      double base_;
  };
}
#endif
