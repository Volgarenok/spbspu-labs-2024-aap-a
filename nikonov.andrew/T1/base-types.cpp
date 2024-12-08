#include "base-types.hpp"
struct point_t 
{
  point_t(float x, float y): 
    x_(x), 
    y_(y)
  {}
  float x_, y_;
};
struct rectangle_t
{
  rectangle_t(float width, float height, point_t pos): 
    width_(width), 
    height_(height), 
    pos_(pos)
  {}
  float width_, height_;
  point_t pos_;
};
