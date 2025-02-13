#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace krylov
{
  class Rectangle: public Shape
  {
  public:
      Rectangle(const point_t& bottomLeft, const point_t& topRight);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t& point) override;
      void move(double dx, double dy) override;
      void scale(double factor) override;
  private:
      point_t bottomLeft_;
      point_t topRight_;
  };
}

#endif
