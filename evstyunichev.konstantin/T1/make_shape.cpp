#include "make_shape.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include "circle.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"
#include "spec_def.hpp"

namespace
{
  using evstyunichev::point_t;

  void form_array(double *, size_t, std::istream &);
  void form_array(point_t *, size_t, std::istream &);

  void form_array(double *ptr, size_t size, std::istream &in)
  {
    for (size_t i = 0; i < size; i++)
    {
      in >> ptr[i];
    }
    return;
  }

  void form_array(point_t *ptr, size_t size, std::istream &in)
  {
    for (size_t i = 0; i < size; i++)
    {
      in >> ptr[i].x >> ptr[i].y;
    }
    return;
  }
}

evstyunichev::Rectangle * evstyunichev::make_rectangle(std::istream &in)
{
  double data[4]{};
  form_array(data, 4, in);
  Rectangle *temp = new Rectangle({data[0], data[1]}, {data[2], data[3]});
  return temp;
}

evstyunichev::Circle * evstyunichev::make_circle(std::istream &in)
{
  double data[3]{};
  form_array(data, 3, in);
  Circle *temp = new Circle({ data[0], data[1] }, data[2]);
  return temp;
}

evstyunichev::Ring * evstyunichev::make_ring(std::istream &in)
{
  double data[4]{};
  form_array(data, 4, in);
  Ring *temp = new Ring({ data[0], data[1] }, data[2], data[3]);
  return temp;
}

evstyunichev::Regular * evstyunichev::make_regular(std::istream &in)
{
  point_t pts[3]{};
  form_array(pts, 3, in);
  double a = findDist(pts[0], pts[1]), b = findDist(pts[1], pts[2]), c = findDist(pts[0], pts[2]);
  if (a > c)
  {
    std::swap(pts[1], pts[2]);
    std::swap(a, c);
  }
  double alpha = std::acos(a / c) * 2.0;
  if (!is_equal(std::pow(c, 2), std::pow(a, 2) + std::pow(b, 2)) || (alpha == 0))
  {
    throw std::invalid_argument("invalid");
  }
  Regular *temp = new Regular(pts[0], alpha, b * 2.0, std::acos((pts[2].x - pts[0].x) / c));
  return temp;
}

evstyunichev::Shape * evstyunichev::make_shape(std::istream &in, const std::string &s)
{
  Shape *shape = nullptr;
  if (s == "RECTANGLE")
  {
    shape = make_rectangle(in);
  }
  else if (s == "CIRCLE")
  {
    shape = make_circle(in);
  }
  else if (s == "RING")
  {
    shape = make_ring(in);
  }
  else if (s == "REGULAR")
  {
    shape = make_regular(in);
  }
  return shape;
}
