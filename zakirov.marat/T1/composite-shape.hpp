#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace zakirov
{
  class CompositeShape final
  {
    public:
      CompositeShape();
      ~CompositeShape();
      double getArea();
      rectangle_t getFrameRect();
      void move(point_t target);
      void move(double bias_x, double bias_y);
      void scale(double k);
      void push_back(Shape * shapes);
      void pop_back();
      Shape * at(size_t id);
      Shape * operator[](size_t id);
      bool empty();
      size_t size();
    private:
      static constexpr size_t shapes_size_ = 10000;
      Shape * shapes_[shapes_size_] = {};
      size_t shapes_quantity_;
  };
}

#endif
