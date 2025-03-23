#include "makeshapes.hpp"
#include "regular.hpp"
#include "ring.hpp"
#include "rectangle.hpp"

namespace
{
  void inputPointsArrayOfSize(std::istream& in, tkach::point_t* double_array, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      in >> double_array[i].x >> double_array[i].y;
    }
  }

  tkach::Rectangle* makeRectangle(std::istream& in)
  {
    tkach::point_t lb_rt_points[2] = {};
    inputPointsArrayOfSize(in, lb_rt_points, 2);
    return new tkach::Rectangle(lb_rt_points[0], lb_rt_points[1]);
  }

  tkach::Ring* makeRing(std::istream& in)
  {
    tkach::point_t ring_center[1] = {};
    inputPointsArrayOfSize(in, ring_center, 1);
    double ring_radius[2] = {};
    for (size_t i = 0; i < 2; ++i)
    {
      in >> ring_radius[i];
    }
    return new tkach::Ring(ring_center[0], ring_radius[0], ring_radius[1]);
  }

  tkach::Regular* makeRegular(std::istream& in)
  {
    tkach::point_t points_x_y[3] = {};
    inputPointsArrayOfSize(in, points_x_y, 3);
    return new tkach::Regular(points_x_y[0], points_x_y[1], points_x_y[2]);
  }
}

tkach::Shape* tkach::makeShape(std::istream& in, const std::string& shape_name)
{
  try
  {
    if (shape_name == "RECTANGLE")
    {
      return makeRectangle(in);
    }
    else if (shape_name == "RING")
    {
      return makeRing(in);
    }
    else if (shape_name == "REGULAR")
    {
      return makeRegular(in);
    }
  }
  catch (const std::logic_error&)
  {
    return nullptr;
  }
  throw std::logic_error("Unsupported figure");
}
