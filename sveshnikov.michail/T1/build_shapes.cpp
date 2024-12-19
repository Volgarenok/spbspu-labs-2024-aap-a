#include "build_shapes.hpp"
#include <iostream>
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"

void sveshnikov::build_rectangle(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (x1 < x2 && y1 < y2)
  {
    shapes[num_shapes] = new Rectangle({x1, y1}, {x2, y2});
  }
  else if (x1 > x2 && y1 > y2)
  {
    shapes[num_shapes] = new Rectangle({x2, y2}, {x1, y1});
  }
  else
  {
    throw std::logic_error("input shape error");
  }
  num_shapes++;
}

void sveshnikov::build_ring(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double ctr_x = 0.0, ctr_y = 0.0, short_radius = 0.0, long_radius = 0.0;
  in >> ctr_x >> ctr_y >> short_radius >> long_radius;
  
}

void sveshnikov::build_ellipse(std::istream &in, Shape **shapes, size_t &num_shapes)
{

}