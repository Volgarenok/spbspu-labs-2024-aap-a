#include "makeShape.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "polygon.hpp"

namespace mozhegova
{
  Rectangle * makeRectangle(std::istream& in);
  Diamond * makeDiamond(std::istream& in);
  Polygon * makePolygon(std::istream& in);
  void inputNum(std::istream& in, point_t * num, size_t n);
}

mozhegova::Shape * mozhegova::makeShape(std::istream& in, std::string shapeName)
{
  if (shapeName == "RECTANGLE")
  {
    return mozhegova::makeRectangle(in);
  }
  else if (shapeName == "DIAMOND")
  {
    return mozhegova::makeDiamond(in);
  }
  else if (shapeName == "POLYGON")
  {
    return mozhegova::makePolygon(in);
  }
  else
  {
    throw std::logic_error("unsupported");
  }
}

mozhegova::Rectangle * mozhegova::makeRectangle(std::istream& in)
{
  constexpr size_t len = 2;
  point_t coor[len] = {};
  inputNum(in, coor, len);
  mozhegova::Rectangle * rect = new mozhegova::Rectangle(coor[0], coor[1]);
  return rect;
}

mozhegova::Diamond * mozhegova::makeDiamond(std::istream& in)
{
  constexpr size_t len = 3;
  point_t coor[len] = {};
  inputNum(in, coor, len);
  Diamond * diam = new Diamond(coor[0], coor[1], coor[2]);
  return diam;
}

mozhegova::Polygon * mozhegova::makePolygon(std::istream& in)
{
  size_t len = 0;
  size_t i = 0;
  double * num = new double[len];
  double p = 0.0;
  while (in >> p)
  {
    if (i == len)
    {
      double * newnum = nullptr;
      try
      {
        newnum = new double[len + 2];
        for (size_t i = 0; i < len; i++)
        {
          newnum[i] = num[i];
        }
      }
      catch (const std::bad_alloc& e)
      {
        delete[] num;
        throw;
      }
      delete[] num;
      num = newnum;
      len += 2;
    }
    num[i] = p;
    i++;
  }
  in.clear();
  point_t * numPoint = nullptr;
  try
  {
    numPoint = new mozhegova::point_t[len / 2];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] num;
    throw;
  }
  for (size_t i = 0; i < len / 2; i++)
  {
    numPoint[i] = {num[i * 2], num[i * 2 + 1]};
  }
  delete[] num;
  Polygon * poly = nullptr;
  try
  {
    poly = new mozhegova::Polygon(len / 2, numPoint);
  }
  catch(const std::bad_alloc& e)
  {
    delete[] numPoint;
    throw;
  }
  catch(const std::invalid_argument& e)
  {
    delete[] numPoint;
    throw;
  }
  delete[] numPoint;
  return poly;
}

void mozhegova::inputNum(std::istream& in, point_t * num, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    in >> num[i].x >> num[i].y;
  }
}
