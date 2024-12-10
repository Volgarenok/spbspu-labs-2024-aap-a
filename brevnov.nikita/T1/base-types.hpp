#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace brevnov
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle
  {
    double width;
    double height;
    point_t pos;
  };
}
#endif