#include "complexquad.hpp"
#include <stdexcept>
#include <cmath>

namespace abramov
{
  void searchInArray(const double *x, double &a, double &b, size_t k)
  {
    if (k >= 1)
    {
      double max = x[0];
      double min = x[0];
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
  }

  void getCoordsOfIntersection(point_t A, point_t B, point_t C, point_t D, double &x, double &y)
  {
    const double k1 = (B.y - A.y) / (B.x - A.x);
    const double b1 = A.y - A.x * k1;
    const double k2 = (D.y - C.y) / (D.x - C.x);
    const double b2 = C.y - C.x * k2;
    if (k1 == k2)
    {
      throw std::logic_error("There is no center\n");
    }
    x = (b2 - b1) / (k1 - k2);
    y = k1 * x + b1;
    if (x == A.x || x == B.x || x == C.x || x == D.x)
    {
      throw std::logic_error("There is no center\n");
    }
    constexpr size_t k = 4;
    double xs[k] = {A.x, B.x, C.x, D.x};
    size_t count = 0;
    for (size_t i = 0; i < k; ++i)
    {
      if (x > xs[i])
      {
        ++count;
      }
    }
    if (count != 2)
    {
      throw std::logic_error("There is no center\n");
    }
  }

  double getTriangleArea(point_t A, point_t B, point_t O)
  {
    const double a = getLength(A, B);
    const double b = getLength(B, O);
    const double c = getLength(O, A);
    const double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
  }

  ComplexQuad::ComplexQuad(point_t A, point_t B, point_t C, point_t D):
    A_(A),
    B_(B),
    C_(C),
    D_(D)
  {
    double x = 0;
    double y = 0;
    getCoordsOfIntersection(A, B, C, D, x, y);
  }

  double ComplexQuad::getArea() const
  {
    const point_t center = getCenterComplexQuad();
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
    point_t pos{(max_x + min_x) / 2, (max_y + min_y) / 2};
    rectangle_t frame_rect{max_x - min_x, max_y - min_y, pos};
    return frame_rect;
  }

  point_t ComplexQuad::getCenterComplexQuad() const
  {
    double x = 0;
    double y = 0;
    getCoordsOfIntersection(A_, B_, C_, D_, x, y);
    point_t center{x, y};
    return center;
  }

  void ComplexQuad::move(point_t p)
  {
    const point_t center = getCenterComplexQuad();
    const double dx = p.x - center.x;
    const double dy = p.y - center.y;
    move(dx, dy);
  }

  void ComplexQuad::move(double dx, double dy)
  {
    constexpr size_t k = 4;
    point_t points[k] = {A_, B_, C_, D_};
    for (size_t i = 0; i < k; ++i)
    {
      changePointCoords(points[i], dx, dy);
    }
    A_ = points[0];
    B_ = points[1];
    C_ = points[2];
    D_ = points[3];
  }

  void ComplexQuad::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Wrong scale coef\n");
    }
    else
    {
      const point_t O = getCenterComplexQuad();
      const double dk = k - 1;
      const double ox = O.x;
      const double oy = O.y;
      constexpr size_t k = 4;
      point_t points[k] = {A_, B_, C_, D_};
      for (size_t i = 0; i < k; ++i)
      {
        double dx = -1 * (ox - points[i].x) * dk;
        double dy = -1 * (oy - points[i].y) * dk;
        changePointCoords(points[i], dx, dy);
      }
      A_ = points[0];
      B_ = points[1];
      C_ = points[2];
      D_ = points[3];
    }
  }

  point_t ComplexQuad::getA() const
  {
    return A_;
  }

  point_t ComplexQuad::getB() const
  {
    return B_;
  }

  point_t ComplexQuad::getC() const
  {
    return C_;
  }

  point_t ComplexQuad::getD() const
  {
    return D_;
  }
}
