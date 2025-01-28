#include "ring.hpp"
#include <stdexcept>
#include <cmath>

namespace
{
  demehin::Polygon createPolygonForRing(const demehin::point_t& center, double radius)
  {
    if (radius <= 0)
    {
      throw std::logic_error("incorrect_shape");
    }

    constexpr size_t VRT_CNT = 130;
    demehin::point_t vrt[VRT_CNT] = {};
    constexpr double PI = 3.1415;
    for (size_t i = 0; i < VRT_CNT; ++i)
    {
      double angle = 2 * PI * i / VRT_CNT;
      double x = center.x + radius * std::cos(angle);
      double y = center.y + radius * std::sin(angle);
      vrt[i] = {x, y};
    }
    demehin::Polygon plg(VRT_CNT, vrt);
    return plg;
  }
}

demehin::Ring::Ring(const point_t& center, double out_r, double in_r):
  inner_plg_(createPolygonForRing(center, in_r)),
  outer_plg_(createPolygonForRing(center, out_r))
{
  if (out_r <= in_r)
  {
    throw std::logic_error("incorrect shape");
  }
}

double demehin::Ring::getArea() const
{
  return outer_plg_.getArea() - inner_plg_.getArea();
}

demehin::rectangle_t demehin::Ring::getFrameRect() const
{
  return outer_plg_.getFrameRect();
}

void demehin::Ring::move(point_t s)
{
  outer_plg_.move(s);
  inner_plg_.move(s);
}

void demehin::Ring::move(double x, double y)
{
  outer_plg_.move(x, y);
  inner_plg_.move(x, y);
}

void demehin::Ring::scaleUnsafely(double k)
{
  outer_plg_.scaleUnsafely(k);
  inner_plg_.scaleUnsafely(k);
}
