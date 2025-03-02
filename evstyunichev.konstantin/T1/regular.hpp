#ifndef REGULAR_HPP
#define REGULAR_HPP
#include <iostream>
#include "base-types.hpp"
#include "make_shape.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  class Regular final: public Shape
  {
    friend Regular * make_regular(std::istream &);
    public:
      Regular(point_t, double, size_t);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double, double) override;
      void move(point_t) override;
      void scale(double k) override;
      double get_r() const;
      double get_R() const;
      point_t getMiddle() const;
      Shape * clone() const override;

    private:
      point_t middle_;
      double alpha_;
      double a_;
      double base_;
      Regular(double *);
  };
  double *createDataRegular(point_t, point_t, point_t);
}
#endif
