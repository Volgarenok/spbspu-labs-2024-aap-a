#ifndef SHAPES_UTILS_HPP
#define SHAPES_UTILS_HPP

#include <iostream>

#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"

namespace zholobov {

  Rectangle* create_rectangle(std::istream& in);
  Square* create_square(std::istream& in);
  Parallelogram* create_parallelogram(std::istream& in);
  void process_scale(Shape** shapes, size_t shape_cnt, point_t pos, double scale_factor);
  void print_shapes(std::ostream& output, Shape** shapes, size_t shape_cnt);
  void delete_shapes(Shape** shapes, size_t shape_cnt);

}

#endif
