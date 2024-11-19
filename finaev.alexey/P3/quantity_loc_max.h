#ifndef QUANTITY_LOC_MAX_H
#define QUANTITY_LOC_MAX_H

#include <cstddef>

namespace finaev
{
  bool is_loc_max(const int *a, size_t stl, size_t i, size_t j);
  size_t quantity_loc_max(const int *matrix, size_t strk, size_t stl);
}

#endif
