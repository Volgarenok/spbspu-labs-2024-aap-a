#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace gavrilova {
  struct point_t {
    double x;
    double y;
    void move(double difX, double difY);
  };
  struct rectangle_t {
    double width;
    double height;
    point_t pos;
  };
}
#endif
