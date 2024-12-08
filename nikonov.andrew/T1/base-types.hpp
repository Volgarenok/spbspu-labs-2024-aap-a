#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace nikonov
{
  struct point_t 
  {
    float x_, y_;
  };
  struct rectangle_t
  {
    float width, height;
    point_t pos;
  };
}
#endif
