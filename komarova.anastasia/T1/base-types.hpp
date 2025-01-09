#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace komarova
{
  struct point_t
  {
  public:
    double x;
    double y;
  };
  struct rectangle_t
  {
   public:
    double width;
    double height;
    point_t pos;
  };
}

#endif
