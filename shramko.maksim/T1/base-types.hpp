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

  inline rectangle_t calculateFrameRect(const point_t* points, size_t count)
  {
    if (count == 0) return {0.0, 0.0, {0.0, 0.0}};
    double x_min = points[0].x, x_max = points[0].x;
    double y_min = points[0].y, y_max = points[0].y;
    for (size_t i = 1; i < count; ++i)
    {
      x_min = std::min(x_min, points[i].x);
      x_max = std::max(x_max, points[i].x);
      y_min = std::min(y_min, points[i].y);
      y_max = std::max(y_max, points[i].y);
    }
    return {x_max - x_min, y_max - y_min, {(x_min + x_max) / 2, (y_min + y_max) / 2}};
  }
}

#endif
