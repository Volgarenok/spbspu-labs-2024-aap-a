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
  point_t scalePoint(point_t p, point_t center, double coef);
}

#endif
