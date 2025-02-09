#ifndef SHAPE_UTILS
#define SHAPE_UTILS

namespace cherkasov
{
  struct point_t
  {
    double x;
    double y;
  };
  void scalePoint(point_t& vertex, const point_t& center, double k);
  void moveVertex(point_t& vertex, double moveX, double moveY);
}
#endif
