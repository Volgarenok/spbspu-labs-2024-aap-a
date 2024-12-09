#ifndef MAIN_UTILS_HPP
#define MAIN_UTILS_HPP

#include <cstddef>
#include "shape.hpp"

namespace kizhin {
  void resetPointers(char**, double**);
  void deleteShapes(Shape* const*, size_t&);
}

#endif
