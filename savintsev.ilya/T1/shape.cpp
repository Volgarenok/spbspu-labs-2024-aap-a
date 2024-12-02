#include "shape.hpp"

void savintsev::scaleRelativeTo(Shape * rhs, point_t p, double k)
{
  if (k <= 0)
  {
    return;
  }
  point_t center = rhs->getFrameRect().pos;
  point_t new_center = {(center.x - p.x) * k + p.x, (center.y - p.y) * k + p.y};
  rhs->move(new_center);
  rhs->scale(k);
}

void savintsev::scaleAllRelativeTo(Shape ** rhs, size_t amt, point_t p, double k)
{
  for (size_t i = 0; i < amt; ++i)
  {
    savintsev::scaleRelativeTo(rhs[i], p, k);
  }
}

void savintsev::printSumAreaAndBorders(std::ostream & out, Shape ** rhs, size_t amt)
{
  savintsev::point_t lL = {0., 0.}, uR = {0., 0.};
  savintsev::rectangle_t rect = {0., 0., {0., 0.}};
  double sumArea = 0.;
  for (size_t i = 0; i < amt; ++i)
  {
    sumArea += rhs[i]->getArea();
  }
  out << sumArea;
  for (size_t i = 0; i < amt; ++i)
  {
    rect = rhs[i]->getFrameRect();
    lL = {rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
    uR = {rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
    out << ' ' << lL.x << ' ' << lL.y << ' ' << uR.x << ' ' << uR.y;
  }
  out << '\n';
}
