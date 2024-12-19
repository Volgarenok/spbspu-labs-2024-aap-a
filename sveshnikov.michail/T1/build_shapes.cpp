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
    num_shapes++;
  }
  else
  {
    throw std::logic_error("input shape error");
  }
}

void sveshnikov::build_ring(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double ctr_x = 0.0, ctr_y = 0.0, radius1 = 0.0, radius2 = 0.0;
  in >> ctr_x >> ctr_y >> radius1 >> radius2;
  if (radius1 > 0 && radius2 > 0 && radius1 > radius2)
  {
    shapes[num_shapes] = new Ring({ctr_x, ctr_y}, radius1, radius2);
    num_shapes++;
  }
  else
  {
    throw std::logic_error("input shape error");
  }
}

void sveshnikov::build_ellipse(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double ctr_x = 0.0, ctr_y = 0.0, vert_radius = 0.0, horiz_radius = 0.0;
  in >> ctr_x >> ctr_y >> vert_radius >> horiz_radius;
  if (vert_radius > 0 && horiz_radius > 0)
  {
    shapes[num_shapes] = new Ring({ctr_x, ctr_y}, vert_radius, horiz_radius);
    num_shapes++;
  }
  else
  {
    throw std::logic_error("input shape error");
  }
}
