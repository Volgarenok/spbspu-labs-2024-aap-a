#ifndef BASE_TYPES
#define BASE_TYPES
#include <cmath>

namespace averenkov
{
  struct point_t
  {
    double x, y;
  };
  struct rectangle_t
  {
    double width, height;
    point_t pos;
  };
}

#endif
