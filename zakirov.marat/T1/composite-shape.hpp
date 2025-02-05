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
      double getArea() noexcept;
      rectangle_t getFrameRect() const;
      void move(point_t target) noexcept;
      void move(double bias_x, double bias_y) noexcept;
      void scale(double k);
      void push_back(Shape * shapes);
      void pop_back();
      Shape * at(size_t id) const;
      Shape * operator[](size_t id) const noexcept;
      bool empty() const noexcept;
      size_t size() const noexcept;
    private:
      static constexpr size_t shapes_size_ = 10000;
      Shape * shapes_[shapes_size_] = {};
      size_t shapes_quantity_;
  };
}

#endif
