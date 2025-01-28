#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

namespace
{
  demehin::Polygon createPolygonForRect(const demehin::point_t& left_bot, const demehin::point_t& right_top)
  {
    demehin::point_t vrt[4] = {};
    vrt[0] = left_bot;
    vrt[1] = {left_bot.x, right_top.y};
    vrt[2] = right_top;
    vrt[3] = {right_top.x, left_bot.y};
    demehin::Polygon plg(4, vrt);
    return plg;
  }
}

demehin::Rectangle::Rectangle(const point_t& left_bot, const point_t& right_top):
  plg_(createPolygonForRect(left_bot, right_top))
{
  if (right_top.x <= left_bot.x || right_top.y <= left_bot.y)
  {
    throw std::logic_error("incorrect_shape");
  }
}

double demehin::Rectangle::getArea() const
{
  return plg_.getArea();
}

demehin::rectangle_t demehin::Rectangle::getFrameRect() const
{
  return plg_.getFrameRect();
}

void demehin::Rectangle::move(point_t s)
{
  plg_.move(s);
}

void demehin::Rectangle::move(double x, double y)
{
  plg_.move(x, y);
}

void demehin::Rectangle::scaleUnsafely(double k)
{
  plg_.scaleUnsafely(k);
}
