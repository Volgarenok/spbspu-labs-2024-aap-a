#ifndef SHAPES_UTILS_HPP
#define SHAPES_UTILS_HPP

#include <iostream>

#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"

namespace zholobov {

  Shape* create_shape(const std::string& shape_name, std::istream& input_stream);
  void process_scale(Shape* const* shapes, size_t shape_cnt, point_t pos, double scale_factor);
  void print_shapes(std::ostream& output, const Shape* const* shapes, size_t shape_cnt);
  void delete_shapes(Shape** shapes, size_t shape_cnt);

}

#endif
