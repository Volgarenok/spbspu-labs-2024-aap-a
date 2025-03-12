#include "makeShape.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "polygon.hpp"

namespace
{
  void inputNum(std::istream & in, mozhegova::point_t * num, size_t n)
  {
    for (size_t i = 0; i < n; i++)
    {
      in >> num[i].x >> num[i].y;
    }
  }
  mozhegova::Rectangle * makeRectangle(std::istream & in)
  {
    constexpr size_t len = 2;
    mozhegova::point_t coor[len] = {};
    inputNum(in, coor, len);
    return new mozhegova::Rectangle(coor[0], coor[1]);
  }
  mozhegova::Diamond * makeDiamond(std::istream & in)
  {
    constexpr size_t len = 3;
    mozhegova::point_t coor[len] = {};
    inputNum(in, coor, len);
    return new mozhegova::Diamond(coor[0], coor[1], coor[2]);
  }
  mozhegova::Polygon * makePolygon(std::istream & in)
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
        catch (const std::bad_alloc &)
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
    mozhegova::point_t * numPoint = nullptr;
    try
    {
      numPoint = new mozhegova::point_t[len / 2];
    }
    catch (const std::bad_alloc &)
    {
      delete[] num;
      throw;
    }
    for (size_t i = 0; i < len / 2; i++)
    {
      numPoint[i] = {num[i * 2], num[i * 2 + 1]};
    }
    delete[] num;
    mozhegova::Polygon * poly = nullptr;
    try
    {
      poly = new mozhegova::Polygon(len / 2, numPoint);
    }
    catch(const std::exception &)
    {
      delete[] numPoint;
      throw;
    }
    delete[] numPoint;
    return poly;
  }
}

mozhegova::Shape * mozhegova::makeShape(std::istream & in, const std::string & shapeName)
{
  if (shapeName == "RECTANGLE")
  {
    return makeRectangle(in);
  }
  else if (shapeName == "DIAMOND")
  {
    return makeDiamond(in);
  }
  else if (shapeName == "POLYGON")
  {
    return makePolygon(in);
  }
  else
  {
    throw std::logic_error("unsupported");
  }
}
