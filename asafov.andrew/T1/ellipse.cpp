#include "ellipse.hpp"
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

asafov::Ellipse::Ellipse(point_t center, double verticalradius, double horizontalradius):
  center_(center),
  verticalradius_(verticalradius),
  horizontalradius_(horizontalradius)
{
  if (verticalradius <= 0.0 || horizontalradius <= 0.0)
  {
    throw std::logic_error("incorrect figure");
  }
}

double asafov::Ellipse::getArea() const
{
  return getPi() * verticalradius_ * horizontalradius_;
}

asafov::rectangle_t asafov::Ellipse::getFrameRect() const
{
  double height = verticalradius_ * 2.0;
  double width = horizontalradius_ * 2.0;
  rectangle_t frect = { width, height, center_ };
  return frect;
}

void asafov::Ellipse::move(double dx, double dy)
{
  increaseDelta(center_, dx, dy);
}

void asafov::Ellipse::move(point_t pos)
{
  center_ = pos;
}

void asafov::Ellipse::unsafeScale(double k)
{
  rectangle_t rect = getFrameRect();
  scalePoint(center_, rect.pos, k);
  verticalradius_ *= k;
  horizontalradius_ *= k;
}
