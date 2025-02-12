#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <iosfwd>
namespace gavrilova {
  struct point_t {
    double x;
    double y;
  };
  struct rectangle_t {
    double width;
    double height;
    point_t pos;
  };
  std::istream& input_point(std::istream&, point_t&);
}
#endif
