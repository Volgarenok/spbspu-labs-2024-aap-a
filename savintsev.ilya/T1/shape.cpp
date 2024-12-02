#include "shape.hpp"
#include <iomanip>

void savintsev::scaleRelativeTo(Shape * rhs, point_t p, double k)
{
  if (k <= 0)
  {
    return;
  }
  point_t jointFirst = rhs->getFrameRect().pos;
  rhs->move(p);
  point_t jointSecond = rhs->getFrameRect().pos;
  point_t vector = {(jointSecond.x - jointFirst.x) * k, (jointSecond.y - jointFirst.y) * k};
  rhs->scale(k);
  rhs->move(-vector.x, -vector.y);
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
  out << std::fixed << std::setprecision(1) << sumArea;
  for (size_t i = 0; i < amt; ++i)
  {
    rect = rhs[i]->getFrameRect();
    lL = {rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
    uR = {rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
    out << ' ' << lL.x << ' ' << lL.y << ' ' << uR.x << ' ' << uR.y;
  }
  out << '\n';
}

void savintsev::destroyShapes(Shape ** rhs, size_t amt)
{
  {
    for (size_t i = 0; i < amt; ++i)
    {
      delete rhs[i];
    }
    delete[] rhs;
  }
}
