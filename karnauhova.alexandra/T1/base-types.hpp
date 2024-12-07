#ifndef BASE-TYPES_HPP
#define BASE-TYPES_HPP

struct point_t{
private:
  double x;
  double y;
};

struct rectangle_t{
private:
  double width;
  double height;
  point_t pos;
};
#endif
