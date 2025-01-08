#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace zakirov
{
  class CompositeShape final
  {
    public:
      CompositeShape(point_t center, double radius);
      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(point_t target);
      void move(double bias_x, double bias_y);
      void scale(double k);
      void push_back(Shape ** shape);
      void pop_back();
      Shape * at(size_t id);
      Shape * operator[](size_t id);
      bool empty();
      size_t size();
    private:
      double radius_;
      double ex_radius_;
      point_t center_;
      size_t ring_quantity_;
      size_t ring_thickness_;
      Shape ** shapes_;
  };
}

#endif
