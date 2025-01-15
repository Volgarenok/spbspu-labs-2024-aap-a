#include "makeshapes.hpp"
#include <string>

tkach::Rectangle* tkach::make_rectangle(std::istream& in)
{
  point_t lb_rt_points[2] = {};
  for (size_t i = 0; i < 2; ++i)
  {
    in >> lb_rt_points[i].x >> lb_rt_points[i].y;
  }
  tkach::Rectangle* rectangle = new tkach::Rectangle({lb_rt_points[0].x, lb_rt_points[0].y}, {lb_rt_points[1].x, lb_rt_points[1].y});
  return rectangle;
}

tkach::Ring* tkach::make_ring(std::istream& in)
{
  double center_x = 0.0, center_y = 0.0;
  double outer_radius = 0.0, inner_radius = 0.0;
  in >> center_x >> center_y >> outer_radius >> inner_radius;
  tkach::Ring* ring = new tkach::Ring({center_x, center_y}, outer_radius, inner_radius);
  return ring;
}

tkach::Regular* tkach::make_regular(std::istream& in)
{
  tkach::point_t point1, point2, point3;
  in >> point1.x >> point1.y;
  in >> point2.x >> point2.y;
  in >> point3.x >> point3.y;
  tkach::Regular* regular = new tkach::Regular({point1.x, point1.y}, {point2.x, point2.y}, {point3.x, point3.y});
  return regular;
}

tkach::Shape* tkach::make_shape(std::istream& in, std::string shape_name)
{
  if (shape_name == "RECTANGLE")
  {
    return make_rectangle(in);
  }
  else if (shape_name == "RING")
  {
    return make_ring(in);
  }
  else if (shape_name == "REGULAR")
  {
    return make_regular(in);
  }
  return nullptr;
}
