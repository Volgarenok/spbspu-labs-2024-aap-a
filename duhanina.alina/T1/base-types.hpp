#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace duhanina
{
  struct point_t
  {
    double x;
    double y;
    point_t calculateOffset(const point_t& newPos) const
    {
      return { newPos.x - x, newPos.y - y };
    }
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
}

#endif
