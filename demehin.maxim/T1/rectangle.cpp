#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

namespace
{
  demehin::point_t* generateVrt(const demehin::point_t left_bot, const demehin::point_t right_top)
  {
    demehin::point_t* vrt = new demehin::point_t[4];
    vrt[0] = left_bot;
    vrt[1] = {left_bot.x, right_top.y};
    vrt[2] = right_top;
    vrt[3] = {right_top.x, left_bot.y};
    return vrt;
  }
}

demehin::Rectangle::Rectangle(point_t left_bot, point_t right_top):
  plg_(demehin::Polygon(4, nullptr))
{
  if (right_top.x <= left_bot.x || right_top.y <= left_bot.y)
  {
    throw std::logic_error("incorrect shape");
  }

  demehin::point_t* vrt = generateVrt(left_bot, right_top);
  plg_.setVertex(vrt, 4);
  delete[] vrt;
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

void demehin::Rectangle::scale(double k)
{
  plg_.scale(k);
}
