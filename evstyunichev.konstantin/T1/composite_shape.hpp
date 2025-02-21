#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"
namespace evstyunichev
{
  class CompositeShape
  {
    public:
      CompositeShape(const CompositeShape &);
      CompositeShape(CompositeShape &&) noexcept;
      CompositeShape(size_t);
      ~CompositeShape();
      CompositeShape & operator=(const CompositeShape &);
      CompositeShape & operator=(CompositeShape &&) noexcept;
      Shape * operator[](size_t) noexcept;
      const Shape * operator[](size_t) const noexcept;
      void pushBack(Shape *);
      void popBack();
      Shape * at(size_t);
      const Shape * at(size_t) const;
      bool empty() const noexcept;
      size_t size() const noexcept;
      double getArea() const;
      CompositeShape * copy() const;
      rectangle_t getFrameRect() const;
      void scale(double, point_t);

    private:
      size_t mxSize_;
      size_t size_;
      double totalSquare_;
      Shape **shapes_;
      void clear() noexcept;
      void swap(CompositeShape &) noexcept;
      void resize(size_t);
  };
}
#endif
