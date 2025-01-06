#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace gavrilova {
  struct point_t {
    double x;
    double y;
    void move(double difX, double difY) noexcept;
    double getDistance(point_t other) noexcept;
    void scaleDistance(point_t other, double k);
  };
  struct rectangle_t {
    double width;
    double height;
    point_t pos;
  };
}
#endif
