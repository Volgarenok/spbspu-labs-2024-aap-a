#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

void sveshnikov::build_rectangle(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  shapes[num_shapes] = new Rectangle({x1, y1}, {x2, y2});
  num_shapes++;
}

void sveshnikov::build_ring(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double ctr_x = 0.0, ctr_y = 0.0, radius1 = 0.0, radius2 = 0.0;
  in >> ctr_x >> ctr_y >> radius1 >> radius2;
  shapes[num_shapes] = new Ring({ctr_x, ctr_y}, radius1, radius2);
  num_shapes++;
}

void sveshnikov::build_ellipse(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double ctr_x = 0.0, ctr_y = 0.0, vert_radius = 0.0, horiz_radius = 0.0;
  in >> ctr_x >> ctr_y >> vert_radius >> horiz_radius;
  shapes[num_shapes] = new Ellipse({ctr_x, ctr_y}, vert_radius, horiz_radius);
  num_shapes++;
}

void sveshnikov::build_square(std::istream &in, Shape **shapes, size_t &num_shapes)
{
  double low_left_x = 0.0, low_left_y = 0.0, side = 0.0;
  in >> low_left_x >> low_left_y >> side;
  shapes[num_shapes] = new Square({low_left_x, low_left_y}, side);
  num_shapes++;
}
