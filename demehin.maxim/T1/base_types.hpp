#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace demehin
{
  struct point_t
  {
  private:
    double x_;
    double y_;
  };

  struct rectangle_t
  {
  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
