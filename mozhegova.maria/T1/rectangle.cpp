#include "rectangle.hpp"
#include <stdexcept>

namespace
{
  mozhegova::Polygon createRect(mozhegova::point_t lowLef, mozhegova::point_t uppRig)
  {
    mozhegova::point_t coor[4] = {};
    coor[0] = lowLef;
    coor[1] = {uppRig.x, lowLef.y};
    coor[2] = uppRig;
    coor[3] = {lowLef.x, uppRig.y};
    mozhegova::Polygon poly(4, coor);
    return poly;
  }
}

mozhegova::Rectangle::Rectangle(point_t lowLef, point_t uppRig):
  poly_(createRect(lowLef, uppRig))
{
  if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}

double mozhegova::Rectangle::getArea() const
{
  return poly_.getArea();
}

mozhegova::rectangle_t mozhegova::Rectangle::getFrameRect() const
{
  return poly_.getFrameRect();
}

void mozhegova::Rectangle::move(point_t p)
{
  poly_.move(p);
}

void mozhegova::Rectangle::move(double dx, double dy)
{
  poly_.move(dx, dy);
}

void mozhegova::Rectangle::scaleImpl(double k)
{
  poly_.scaleImpl(k);
}
