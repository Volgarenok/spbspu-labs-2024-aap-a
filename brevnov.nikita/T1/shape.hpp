#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include "base-types.hpp"
namespace brevnov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t new_centre) = 0;
    virtual void move(double dx, double dy) = 0;
    void check_scale(double n);
    virtual void scale(double n) = 0;
    virtual ~Shape() = default;
  };
  double get_sum_areas(const Shape * const * shapes, size_t count);
  void destroy_shapes(Shape** shapes, size_t count);
  void scale_shapes(Shape * const * shapes, size_t count, point_t scale_p, double ratio);
  void print_frame_coordinates(const Shape * const * shapes, size_t count, std::ostream & out);
  void find_frame_coordinates(rectangle_t frame, std::ostream& out);
}
#endif
