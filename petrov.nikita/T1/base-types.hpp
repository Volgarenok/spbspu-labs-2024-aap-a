#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace petrov
{
  struct point_t
  {
  private:
    double x_, y_;
  };

  struct rectangle_t
  {
  private:
    double width_, height_, pos_;
  };
}
#endif
