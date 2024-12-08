#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace nikonov
{
  struct point_t 
  {
    point_t();
    point_t(float x, float y);
    float x_, y_;
  };
  struct rectangle_t
  {
    rectangle_t(point_t lbp, point_t rtp);
    float width_, height_;
    point_t pos_;
  };
}
#endif
