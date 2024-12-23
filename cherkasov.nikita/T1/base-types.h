#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace cherkasov
{
  struct point_t
  {
    double x, y;
  };

  struct rectangle_t
  {
    double width, height;
    point_t pos;
  };
}
#endif
