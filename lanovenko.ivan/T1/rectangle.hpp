#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace lanovenko
{
  class Rectangle : public Shape
  {
    public:
      Rectangle(point_t p1, point_t p2);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t p);
      virtual void move(double dx, double dy);
      void unsScale(double k) override;
    private:
      point_t leftlower;
      point_t rightupper;
  };
}

#endif
