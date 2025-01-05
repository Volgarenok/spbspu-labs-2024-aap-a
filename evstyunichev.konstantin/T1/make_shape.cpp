#include "make_shape.hpp"
#include <cmath>
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"

namespace
{
  const double prec = 0.0000001;
  bool isEqual(double, double, double p = prec);
  size_t goodCos(double);

  bool isEqual(double a, double b, double p)
  {
    if (std::abs(a - b) <= p)
    {
      return 1;
    }
    return 0;
  }

  size_t goodCos(double d)
  {
    int l = 3, r = 1e5, mid = 0;
    double cur = 0;
    while (l <= r)
    {
      mid = (l + r) / 2;
      cur = std::cos(M_PI / mid);
      if (isEqual(cur, d))
      {
        return mid;
      }
      else if (cur < d)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }
    return 0;
  }
}

evstyunichev::Rectangle * evstyunichev::make_rectangle(std::istream &in)
{
  double x1{}, y1{}, x2{}, y2{};
  in >> x1 >> y1 >> x2 >> y2;
  if (!in || (x1 > x2) || (y1 > y2))
  {
    return nullptr;
  }
  Rectangle *temp = new Rectangle({x1, y1}, {x2, y2});
  return temp;
}

evstyunichev::Circle * evstyunichev::make_circle(std::istream &in)
{
  double x{}, y{}, r{};
  in >> x >> y >> r;
  if (r <= 0)
  {
    return nullptr;
  }
  Circle *temp = new Circle({x, y}, r);
  return temp;
}

evstyunichev::Ring * evstyunichev::make_ring(std::istream &in)
{
  double x{}, y{}, R{}, r{};
  in >> x >> y >> R >> r;
  if ((r <= 0) || (R <= r))
  {
    return nullptr;
  }
  Ring *temp = new Ring({x, y}, R, r);
  return temp;
}

evstyunichev::Regular * evstyunichev::make_regular(std::istream &in)
{
  double x1{}, y1{}, x2{}, y2{}, x3{}, y3{}, base{};
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a = findDist({x1, y1}, {x2, y2}), b = findDist({x1, y1}, {x3, y3}),
    c = findDist({x3, y3}, {x2, y2});
  double target = y3 - y1;
  if (a > b)
  {
    std::swap(a, b);
    target = y2 - y1;
  }
  if (isEqual(pow(a, 2) + pow(c, 2), pow(b, 2)))
  {
    base = std::asin(target / b);
    size_t n = goodCos(a / b);
    if (n)
    {
      Regular * temp = new Regular({x1, y1}, n, 2 * b * std::sin(M_PI / n), base);
      return temp;
    }
  }
  return nullptr;
}
