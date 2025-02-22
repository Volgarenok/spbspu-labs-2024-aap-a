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
  std::istream& inputPoints(std::istream&, point_t* points, size_t n);
  std::istream& inputPoint(std::istream& in, point_t& ob);
}
#endif
