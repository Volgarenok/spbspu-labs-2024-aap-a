#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace balashov
{
  struct point_t
  {
    double x_;
    double y_;
  };

  struct rectangle_t
  {
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
