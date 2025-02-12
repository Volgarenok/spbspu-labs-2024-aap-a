#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <iosfwd>
namespace gavrilova {
  struct point_t {
    double x;
    double y;
    friend std::istream& operator>>(std::istream& in, point_t& ob);
  };
  struct rectangle_t {
    double width;
    double height;
    point_t pos;
  };
  std::istream& input_points(std::istream&, point_t* points, size_t n);
  std::istream& operator>>(std::istream& in, point_t& ob);
}
#endif
