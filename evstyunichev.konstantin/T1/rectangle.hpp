#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  class Rectangle final: public Shape
  {
    public:
      Rectangle(point_t, point_t);
      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double, double) override;
      void move(point_t) override;
      void scale(double k) override;
      Shape * clone() const override;

    private:
      point_t leftDown_;
      point_t rightUp_;
      point_t getMiddle() const;
  };
}
#endif
