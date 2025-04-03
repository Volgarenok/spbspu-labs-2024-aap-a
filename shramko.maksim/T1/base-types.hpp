#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iostream>

namespace shramko
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

  inline std::ostream& operator<<(std::ostream& out, const rectangle_t& rect)
  {
    out << rect.pos.x - rect.width / 2 << " " << rect.pos.y - rect.height / 2 << " ";
    out << rect.pos.x + rect.width / 2 << " " << rect.pos.y + rect.height / 2;
    return out;
  }
}

#endif
