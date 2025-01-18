#include "makeshapes.hpp"
#include <string>
#include "regular.hpp"
#include "ring.hpp"
#include "rectangle.hpp"

namespace
{
  void inputDoubleArrayOfFour(std::istream& in, double* double_array, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      in >> double_array[i];
    }
  }

  tkach::Rectangle* make_rectangle(std::istream& in)
  {
    double lb_rt_points[4] = {};
    inputDoubleArrayOfFour(in, lb_rt_points, 4);
    return new tkach::Rectangle({lb_rt_points[0], lb_rt_points[1]}, {lb_rt_points[2], lb_rt_points[3]});
  }

  tkach::Ring* make_ring(std::istream& in)
  {
    double ring_feature[4] = {};
    inputDoubleArrayOfFour(in, ring_feature, 4);
    return new tkach::Ring({ring_feature[0], ring_feature[1]}, ring_feature[2], ring_feature[3]);
  }

  tkach::Regular* make_regular(std::istream& in)
  {
    double points_x_y[6] = {};
    inputDoubleArrayOfFour(in, points_x_y, 6);
    tkach::point_t point1 = {points_x_y[0], points_x_y[1]};
    tkach::point_t point2 = {points_x_y[2], points_x_y[3]};
    tkach::point_t point3 = {points_x_y[4], points_x_y[5]};
    return new tkach::Regular(point1, point2, point3);
  }
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
