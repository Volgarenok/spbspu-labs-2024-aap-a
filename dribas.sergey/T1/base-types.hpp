#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace dribas
{
  struct Point_t
  {
    double x_;
    double y_;
  };
  struct Rectangle_t
  {
    double width_;
    double height_;
    Point_t pos_;
  };
}
#endif
