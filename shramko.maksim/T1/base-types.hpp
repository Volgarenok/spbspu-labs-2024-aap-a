#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <cmath>
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

  inline double distance(const point_t& p1, const point_t& p2)
  {
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
  }
}

#endif
