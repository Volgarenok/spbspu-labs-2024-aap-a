#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

namespace abramov
{
  void searchInArray(double *x, double &a, double &b, size_t k)
  {
    double max = std::numeric_limits< double >::min();
    double min = std::numeric_limits< double >::max();
    for (size_t i = 0; i < k; ++i)
    {
      if (x[i] > max)
      {
        max = x[i];
      }
      if (x[i] < min)
      {
        min = x[i];
      }
    }
    a = min;
    b = max;
  }

  double getTriangleArea(point_t A, point_t B, point_t O)
  {
    double a = getLength(A, B);
    double b = getLength(B, O);
    double c = getLength(O, A);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
  }

  ComplexQuad::ComplexQuad(point_t A, point_t B, point_t C, point_t D):
  A_(A), B_(B), C_(C), D_(D)
  {}

  double ComplexQuad::getArea() const
  {
    point_t center = getCenterComplexQuad();
    return getTriangleArea(A_, D_, center) + getTriangleArea(B_, C_, center);
  }

  rectangle_t ComplexQuad::getFrameRect() const
  {
    constexpr size_t k = 4;
    double x[k] = {A_.x, B_.x, C_.x, D_.x};
    double y[k] = {A_.y, B_.y, C_.y, D_.y};
    double max_x = 0;
    double min_x = 0;
    double max_y = 0;
    double min_y = 0;
    searchInArray(x, min_x, max_x, k);
    searchInArray(y, min_y, max_y, k);
    rectangle_t frame_rect;
    frame_rect.width = max_x - min_x;
    frame_rect.height = max_y - min_y;
    point_t pos;
    pos.x = (max_x + min_x) / 2;
    pos.y = (max_y + min_y) / 2;
    frame_rect.pos = pos;
    return frame_rect;
  }

  point_t ComplexQuad::getCenterComplexQuad() const
  {
    double k1 = (B_.y - A_.y) / (B_.x - A_.x);
    double b1 = A_.y - A_.x * k1;
    double k2 = (D_.y - C_.y) / (D_.x - C_.x);
    double b2 = C_.y - C_.x * k2;
    if (k1 == k2)
    {
      throw std::logic_error("There is no center\n");
    }
    double x = (b2 - b1) / (k1 - k2);
    double y = k1 * x + b1;
    point_t center;
    center.x = x;
    center.y = y;
    return center;
  }

  void ComplexQuad::move(point_t p)
  {
    point_t center = getCenterComplexQuad();
    double dx = p.x - center.x;
    double dy = p.y - center.y;
    move(dx, dy);
  }

  void ComplexQuad::move(double dx, double dy)
  {
    A_.x += dx;
    B_.x += dx;
    C_.x += dx;
    D_.x += dx;
    A_.y += dy;
    B_.y += dy;
    C_.y += dy;
    D_.y += dy;
  }

  void ComplexQuad::scale(double k)
  {
    point_t O = getCenterComplexQuad();
    const double dk = k - 1;
    A_.x += (O.x - A_.x) * dk;
    A_.y += (O.y - A_.y) * dk;
    B_.x += (O.x - B_.x) * dk;
    B_.y += (O.y - B_.y) * dk;
    C_.x += (O.x - C_.x) * dk;
    C_.y += (O.y - C_.y) * dk;
    D_.x += (O.x - D_.x) * dk;
    D_.y += (O.x - D_.y) * dk;
  }
}
