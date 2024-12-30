#include "shape.hpp"
#include <cstring>
#include <iomanip>
#include "rectangle.hpp"
#include "concave.hpp"
#include "complexquad.hpp"

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
  savintsev::point_t lL = {0.0, 0.0}, uR = {0.0, 0.0};
  savintsev::rectangle_t rect = {0.0, 0.0, {0.0, 0.0}};
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

namespace
{
  void readDblfromDesc(double * numbers, size_t amt);

  void readDblfromDesc(double * numbers, size_t amt)
  {
    char * token = nullptr;
    for (size_t i = 0; i < amt; ++i)
    {
      token = std::strtok(nullptr, " ");
      if (!token)
      {
        break;
      }
      numbers[i] = std::atof(token);
    }
  }
}

int savintsev::actWithShpByDesc(char * desc, Shape ** rhs, size_t & amt, point_t & p, double & k)
{
  if (desc[0] == '\0')
  {
    return -1;
  }
  char * token = std::strtok(desc, " ");
  try
  {
    if (!std::strcmp(token, "RECTANGLE"))
    {
      double numbers[4] = {0.0, 0.0, 0.0, 0.0};
      readDblfromDesc(numbers, 4);
      Rectangle * Rect = new Rectangle({numbers[0], numbers[1]}, {numbers[2], numbers[3]});
      rhs[amt++] = Rect;
      return 0;
    }
    if (!std::strcmp(token, "CONCAVE"))
    {
      double n[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
      readDblfromDesc(n, 8);
      Concave * Conc = new Concave({n[0], n[1]}, {n[2], n[3]}, {n[4], n[5]}, {n[6], n[7]});
      rhs[amt++] = Conc;
      return 0;
    }
    if (!std::strcmp(token, "COMPLEXQUAD"))
    {
      double n[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
      readDblfromDesc(n, 8);
      Complexquad * Comp = new Complexquad({n[0], n[1]}, {n[2], n[3]}, {n[4], n[5]}, {n[6], n[7]});
      rhs[amt++] = Comp;
      return 0;
    }
  }
  catch (const std::invalid_argument & e)
  {
    return 2;
  }
  if (!std::strcmp(token, "SCALE"))
  {
    double numbers[3] = {0.0, 0.0, 0.0};
    readDblfromDesc(numbers, 3);
    if (numbers[2] <= 0)
    {
      return -1;
    }
    p = {numbers[0], numbers[1]};
    k = numbers[2];
    return 1;
  }
  return -1;
}

void savintsev::destroyArray(Shape ** rhs, size_t amt)
{
  for (size_t i = 0; i < amt; ++i)
  {
    delete rhs[i];
  }
}
