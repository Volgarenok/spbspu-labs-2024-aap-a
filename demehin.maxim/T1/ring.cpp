#include "ring.hpp"
#include <stdexcept>
#include <cmath>

namespace
{
  demehin::point_t* generateVrt(const demehin::point_t center, double radius, size_t vrt_cnt)
  {
    demehin::point_t* vrt = new demehin::point_t[vrt_cnt];
    constexpr double PI = 3.1415;
    for (size_t i = 0; i < vrt_cnt; ++i)
    {
      double angle = 2 * PI * i / vrt_cnt;
      double x = center.x + radius * std::cos(angle);
      double y = center.y + radius * std::sin(angle);
      vrt[i] = {x, y};
    }
    return vrt;
  }
}

demehin::Ring::Ring(point_t center, double out_r, double in_r):
  inner_plg_(130, generateVrt(center, in_r, 130)),
  outer_plg_(130, generateVrt(center, out_r, 130))
{
  if (out_r <= in_r || out_r <= 0 || in_r <= 0)
  {
    throw std::logic_error("incorrect shape");
  }

  //demehin::point_t* outerVrt = generateVrt(center, out_r, 130);
  //demehin::point_t* innerVrt = nullptr;
  //try
  //{
    //innerVrt = generateVrt(center, in_r, 130);
  //}
  //catch (std::bad_alloc& e)
  //{
    //delete[] outerVrt;
  //}

  //outer_plg_.setVertex(outerVrt, 130);
  //inner_plg_.setVertex(innerVrt, 130);

  //delete[] outerVrt;
  //delete[] innerVrt;
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
  inner_plg_.move(s);
  outer_plg_.move(s);
}

void demehin::Ring::move(double x, double y)
{
  inner_plg_.move(x, y);
  outer_plg_.move(x, y);
}

void demehin::Ring::scale(double k)
{
  inner_plg_.scale(k);
  outer_plg_.scale(k);
}
