#include "rectangle.hpp"
#include <stdexcept>

mozhegova::Rectangle::Rectangle(point_t lowLef, point_t uppRig):
  poly_(nullptr)
{
  if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  point_t coor[4] = {};
  coor[0] = lowLef;
  coor[1] = {uppRig.x, lowLef.y};
  coor[2] = uppRig;
  coor[3] = {lowLef.x, uppRig.y};
  poly_ = new Polygon(4, coor);
}

mozhegova::Rectangle::~Rectangle()
{
  delete poly_;
}

double mozhegova::Rectangle::getArea() const
{
  return poly_->getArea();
}

mozhegova::rectangle_t mozhegova::Rectangle::getFrameRect() const
{
  return poly_->getFrameRect();
}

void mozhegova::Rectangle::move(point_t p)
{
  poly_->move(p);
}

void mozhegova::Rectangle::move(double dx, double dy)
{
  poly_->move(dx, dy);
}

void mozhegova::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  poly_->scale(k);
}
