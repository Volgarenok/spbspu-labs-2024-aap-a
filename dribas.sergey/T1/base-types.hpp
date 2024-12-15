#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace dribas
{
  struct point_t
  {
    double x_;
    double y_;
  };
  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}
#endif
