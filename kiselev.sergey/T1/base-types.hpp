#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace kiselev
{
  class point_t
  {
    double x;
    double y;
  };
  class rectagle_t
  {
    double width;
    double height;
    point_t pos;
  };
}
#endif
