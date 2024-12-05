#include "complexquad.hpp"

namespace abramov
{
  ComplexQuad::ComplexQuad(point_t A, point_t B, point_t C, point_t D):
  A_(A), B_(B), C_(C), D_(D)
  {}

  double ComplexQuad::getArea() const
  {
    return 0;
  }

  rectangle_t ComplexQuad::getFrameRect() const
  {
    rectangle_t frame_rect;
    return frame_rect;
  }

  void ComplexQuad::move(point_t p)
  {
    point_t p1 = p;
    double k = 0;
    k += p1.x;
  }

  void ComplexQuad::move(double dx, double dy)
  {
    double x = dx;
    double y = dy;
    x += y;
  }

  void ComplexQuad::scale(double k)
  {
    double kk = k;
    kk += k;
  }
}
