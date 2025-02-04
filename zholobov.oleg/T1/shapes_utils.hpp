#ifndef SHAPES_UTILS_HPP
#define SHAPES_UTILS_HPP

#include <iostream>

#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"

namespace zholobov {

  Shape* create_shape(const std::string& shape_name, std::istream& input_stream);

}

#endif
