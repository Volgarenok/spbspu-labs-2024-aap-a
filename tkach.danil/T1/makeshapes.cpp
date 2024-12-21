#include "makeshapes.hpp"

tkach::Rectangle* tkach::make_rectangle(std::istream& in)
{
  double left_bot_point_x = 0.0, left_bot_point_y = 0.0;
  double right_top_point_x = 0.0, right_top_point_y = 0.0;
  in >> left_bot_point_x >> left_bot_point_y >> right_top_point_x >> right_top_point_y;
  tkach::Rectangle* rectangle = new tkach::Rectangle({left_bot_point_x, left_bot_point_y}, {right_top_point_x, right_top_point_y});
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
