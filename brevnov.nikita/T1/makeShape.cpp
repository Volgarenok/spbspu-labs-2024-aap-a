#include "makeShape.hpp"
#include <iostream>
#include <string>
#include <exception>

namespace brevnov
{
  Shape * make_rectangle(std::string name_shape, std::istream& in)
  {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
    in >> x1 >> y1 >> x2 >> y2;
    if (in.fail())
    {
      return nullptr;
    }
    try
    {
      if (name_shape == "RECTANGLE")
      {
        return new Rectangle({x1, y1}, {x2, y2});
      }
      else
      {
        return new BigRectangle({x1, y1}, {x2, y2});
      }
    }
    catch (const std::invalid_argument& e)
    {
      return nullptr;
    }
  }

  Diamond * make_diamond(std::istream& in)
  {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (in.fail())
    {
      return nullptr;
    }
    try
    {
      return new Diamond({x1, y1}, {x2, y2}, {x3, y3});
    }
    catch (const std::invalid_argument& e)
    {
      return nullptr;
    }
  }

  Ellipse * make_ellipse(std::istream& in)
  {
    double x = 0.0, y = 0.0;
    in >> x >> y;
    point_t center = {x, y};
    double r1 = 0.0, r2 = 0.0;
    in >> r1 >> r2;
    if (in.fail())
    {
      return nullptr;
    }
    try
    {
      return new Ellipse(center, r1, r2);
    }
    catch (const std::invalid_argument& e)
    {
      return nullptr;
    }
  }

  point_t scale(std::istream & in)
  {
    double x = 0.0, y = 0.0;
    in >> x >> y;
    if (in.fail())
    {
      throw std::invalid_argument("Not correct parameter");
    }
    return {x, y};
  }

  Shape * make_shape(std::string name_shape, std::istream & in)
  {
    if (name_shape == "RECTANGLE" || name_shape == "BIGRECTANGLE")
    {
      return make_rectangle(name_shape, in);
    }
    if (name_shape == "ELLIPSE")
    {
      return make_ellipse(in);
    }
    if (name_shape == "DIAMOND")
    {
      return make_diamond(in);
    }
    return nullptr;
  }
}
