#ifndef SHAPES_UTILS_HPP
#define SHAPES_UTILS_HPP

#include <istream>
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"

namespace zholobov {

  Rectangle* create_rectangle(std::istream& in);
  Square* create_square(std::istream& in);
  Parallelogram* create_parallelogram(std::istream& in);
  void process_scale(std::istream& in, Shape** shapes, size_t shape_cnt);
  void print_shapes(Shape** shapes, size_t shape_cnt);
  void delete_shapes(Shape** shapes, size_t shape_cnt);

}

#endif
